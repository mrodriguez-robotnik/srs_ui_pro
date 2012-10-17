#include "SkypeFunctions.h"
#include "keypair.h"

//SKYPEFUNCTIONS
SkypeFunctions::SkypeFunctions(){

    accountName = "srs_ui_pro";
    accountPsw  ="Robotnik2012";

    inetAddr = "127.0.0.1";
    portNum = 8963;
    skype = 0;
    connected = false;
    itemIndex = -1;
    calling = false;

    micro_muted = sound_muted = false;
}

SkypeFunctions::~SkypeFunctions(){
    //dtor
}

void SkypeFunctions::initialize(){

    // At this point the SDK runtime should be already up and running.
    skype = new MySkype();

    if (!getKeyPair())
        throw SkypeException("Can't initialize. (getKeyPair)\n");

    skype->init(keyBuf, inetAddr, portNum, "streamlog.txt");

    if (!skype->start())
        throw SkypeException("Can't initialize. (start)\n");

}

int SkypeFunctions::connect(wxListCtrl *contactList){

   printf("[SKYPE]: Getting account...\n");
  if (skype->GetAccount(accountName.c_str(), account))
  {
    printf("[SKYPE]: Logging in...\n");
    account->LoginWithPassword(accountPsw.c_str(), false, false);

    // Loop until LoggedIn or login failure during 3 seconds
    int sec = 0;
    while ( (!account->loggedIn) && (!account->loggedOut) && sec<3 ) { Delay(1); sec++; };

    if (account->loggedIn)
    {
        //log->AppendText(wxString("Connected to Skype.\n", wxConvUTF8));
        //initChat();
        MyContactGroup::Ref skypeNamesContactGroup;
        if (!skype->GetHardwiredContactGroup(ContactGroup::ONLINE_BUDDIES, skypeNamesContactGroup)) throw SkypeException("Can't obtain contacts. (GetHardwiredContactGroup)\n");

        if (!skypeNamesContactGroup->GetContacts(skypeNamesContactGroup->contactList)) throw SkypeException("Can't obtain contacts. (GetContacts)\n");
        fetch(skypeNamesContactGroup->contactList);


         for (uint i = 0; i < skypeNamesContactGroup->contactList.size(); i++)
         {
            SEString id;
            if (!skypeNamesContactGroup->contactList[i]->GetIdentity(id)) throw SkypeException("Can't obatin contact id.\n");

            SEString contactName;
            if (!skypeNamesContactGroup->contactList[i]->GetPropDisplayname(contactName)) throw SkypeException("Can't obtain contact name.\n");

            SEString statusAsText;
            Contact::AVAILABILITY availability;
            if (!skypeNamesContactGroup->contactList[i]->GetPropAvailability(availability)) throw SkypeException("Cant obtain contact availability.\n");
            statusAsText = tostring(availability);

            std::string auxS = (const char*) contactName;
            std::string auxS2 = (const char*) statusAsText;
            std::string auxS3 = (const char*) id;

            std::string status = "Contact::AVAILABILITY.";
            auxS2 = auxS2.substr(status.size(), auxS2.size());

            wxString auxWXS(auxS.c_str(), wxConvUTF8);
            wxString auxWXS2(auxS2.c_str(), wxConvUTF8);
            wxString auxWXS3(auxS3.c_str(), wxConvUTF8);

            long itemIndex = contactList->InsertItem(0, auxWXS3);
            contactList->SetItem(itemIndex, 1, auxWXS2);
            contactList->SetItem(itemIndex, 2, auxWXS);
         };

        connected = true;
        //getchar();
        return 1;
    }
    else if (account->loggedOut)
        return 0;
    else
        return 0;
  }
  else
    throw SkypeException("Can't obtain account.\n");
}

void SkypeFunctions::showContactList(wxListCtrl *contactList){

    contactList->DeleteAllItems();
    MyContactGroup::Ref skypeNamesContactGroup;
    if (!skype->GetHardwiredContactGroup(ContactGroup::ONLINE_BUDDIES, skypeNamesContactGroup)) throw SkypeException("Can't obtain contacts. (GetHardwiredContactGroup)\n");

    if (!skypeNamesContactGroup->GetContacts(skypeNamesContactGroup->contactList)) throw SkypeException("Can't obtain contacts. (GetContacts)\n");
    fetch(skypeNamesContactGroup->contactList);


     for (uint i = 0; i < skypeNamesContactGroup->contactList.size(); i++)
     {
        SEString id;
        if (!skypeNamesContactGroup->contactList[i]->GetIdentity(id)) throw SkypeException("Can't obatin contact id.\n");


        SEString contactName;
        if (!skypeNamesContactGroup->contactList[i]->GetPropDisplayname(contactName)) throw SkypeException("Can't obtain contact name.\n");

        SEString statusAsText;
        Contact::AVAILABILITY availability;
        if (!skypeNamesContactGroup->contactList[i]->GetPropAvailability(availability)) throw SkypeException("Cant obtain contact availability.\n");
        statusAsText = tostring(availability);

        std::string auxS = (const char*) contactName;
        std::string auxS2 = (const char*) statusAsText;
        std::string auxS3 = (const char*) id;

        std::string status = "Contact::AVAILABILITY.";
        auxS2 = auxS2.substr(status.size(), auxS2.size());

        wxString auxWXS(auxS.c_str(), wxConvUTF8);
        wxString auxWXS2(auxS2.c_str(), wxConvUTF8);
        wxString auxWXS3(auxS3.c_str(), wxConvUTF8);

        long itemIndex = contactList->InsertItem(0, auxWXS3);
        contactList->SetItem(itemIndex, 1, auxWXS2);
        contactList->SetItem(itemIndex, 2, auxWXS);
     };
}

void SkypeFunctions::disconnect(wxListCtrl *contactList){

    if (account->loggedIn){
            account->Logout(false);
            while (!account->loggedOut) { Delay(1); }; // Loop until LoggedOut
            contactList->ClearAll();
            printf("[SKYPE]: Cleaning up.\n");
            skype->stop();
            delete skype;
            printf("[SKYPE]: Done.\n");
            connected = false;
    }

}

void SkypeFunctions::initCall(std::string selectedContact){

    calling = true;
    printf("[SKYPE]: Calling value %d\n", calling);

    long inputDeviceIdx, outputDeviceIdx;
    inputDeviceIdx = 0;
    outputDeviceIdx = 0;

    if (skype->SetupAudioDevices(inputDeviceIdx, outputDeviceIdx))
    {
        SEString myCallTarget = selectedContact.data();
        if (!skype->GetConversationByIdentity(myCallTarget, conv)) throw SkypeException("Can't obtain conversation id.\n");
        conv->RingOthers();
    }
    else
    {
        printf("[SKYPE]: Unable to set audio devices.\n");
        calling = false;
        throw SkypeException("Unable to set audio devices.\n");
    }
}

void SkypeFunctions::initChat(){

    if (!skype->GetConversationList(skype->inbox, Conversation::INBOX_CONVERSATIONS)) throw SkypeException("Can't get conversation list.\n");
    fetch(skype->inbox);
    printf("[SKYPE]: Now accepting incoming chat messages.\n");
}

void SkypeFunctions::sendText(std::string selectedContact, std::string text){

    SEString myCallTarget = selectedContact.data();
    if (!skype->GetConversationByIdentity(myCallTarget, conv)) throw SkypeException(" Unable to create conversation.\n");

    if (text.size() > 0)
    {
        Message::Ref reply;
        conv->PostText(text.c_str(), reply, false);
        contact_event = selectedContact;
    }
}

void SkypeFunctions::stopCall(Sid::String userName){

    Conversation::Ref cv;
    skype->GetConversationByIdentity(userName, cv);
    if (!skype->callFinished)
    {
        cv->LeaveLiveSession();
        calling = false;
    };
}

void SkypeFunctions::Delay(int Sec){
    sleep(Sec);
};

void SkypeFunctions::muteMicro(bool action){

    if (!skype->MuteMicrophone(action)) throw SkypeException("Can't mute microphone.\n");
    micro_muted = action;
}

bool SkypeFunctions::isMicroMuted(){

    return micro_muted;
}

void SkypeFunctions::muteSound(bool action){

    if (!skype->MuteSpeakers(action)) throw SkypeException("Can't mute sound.\n");
    sound_muted = action;
}

bool SkypeFunctions::isSoundMuted(){

    return sound_muted;
}

SkypeFunctions::user_info SkypeFunctions::getUserInfo(SEString userName){

    user_info ui;

    MyContact::Ref contact;
    if (!skype->GetContact(userName, contact)) throw SkypeException("Can't obtain contact.\n");

    Sid::Binary avatar;
    Sid::String name, city, country;

    contact->GetPropAvatarImage(avatar);
    contact->GetPropFullname(name);
    contact->GetPropCity(city);
    contact->GetPropCountry(country);

    int size = avatar.size();
    unsigned char puntero[size];
    wxImage theBitmap;

    if (size>0)
    {
        for (int i=0; i<size; i++)
            puntero[i] = (char)avatar[i];

        wxMemoryInputStream pngStream(puntero, size);
        theBitmap.LoadFile(pngStream, wxBITMAP_TYPE_JPEG);
    }
    else
        theBitmap.LoadFile(wxString(_("./img/avatar_prueba.jpg")));

    ui.avatar = theBitmap;
    ui.name = name;
    ui.location = city+", "+country;

    return ui;
}

bool SkypeFunctions::isCalling(){

    return skype->isLiveSessionUp;
}

void SkypeFunctions::acceptCall(std::string userName){

    calling = true;
    Conversation::Ref cr;
    if (!skype->GetConversationByIdentity(userName.c_str(), cr)) throw SkypeException("Can't obtain conversation by identity.\n");
    if (!cr->JoinLiveSession()) throw SkypeException("Can't join to live session.\n");
}

void SkypeFunctions::allowNewMessageEvent(){
    skype->message_event = false;
}

void SkypeFunctions::allowNewIncomingCallEvent(){
    skype->incomingCall_event = false;
}

bool SkypeFunctions::messageEvent(){
    return skype->message_event;
}

bool SkypeFunctions::incomingCallEvent(){
    return skype->incomingCall_event;
}

std::string SkypeFunctions::textEvent(){
    return skype->text_event;
}

std::string SkypeFunctions::incomingCallMessageEvent(){
    return skype->incomingCall_message;
}


//MYSKYPE
void MySkype::OnMessage(const Message::Ref& message, const bool&, const Message::Ref&, const ConversationRef& conversation){

  while (message_event){ usleep(10000); }

  Message::TYPE messageType;
  message->GetPropType(messageType);

  if (messageType == Message::POSTED_TEXT)
  {
    SEIntList propIds;
    SEIntDict propValues;
    propIds.append(Message::P_AUTHOR);
    propIds.append(Message::P_BODY_XML);
    propValues = message->GetProps(propIds);

    if (propValues[0] != accountName.c_str())
    {
        std::string aux;
        aux = propValues[0] + ": " + propValues[1] + "\n";

        //log->SetDefaultStyle(wxTextAttr(*wxRED));
        //log->AppendText(wxString(aux.c_str(), wxConvUTF8));
        text_event = aux;
        colour_event = *wxRED;
        message_event = true;
    }
  }

}

void MySkype::OnConversationListChange(const ConversationRef &conversation, const Conversation::LIST_TYPE &type, const bool &added){

  if (type == Conversation::LIVE_CONVERSATIONS)
  {
    Conversation::LOCAL_LIVESTATUS liveStatus;
    if (!conversation->GetPropLocalLivestatus(liveStatus)) throw SkypeException("Can't obtain contact status.\n");
    SEString liveStatusAsString = tostring(liveStatus);
    printf("[SKYPE]: OnConversationListChange : %s\n", (const char*)liveStatusAsString);

    if (liveStatus == Conversation::RINGING_FOR_ME || liveStatus == Conversation::NONE)
    {
        printf("[SKYPE]: RING RING..\n");
        printf("[SKYPE]: Picking up call from MySkype::OnConversationListChange\n");
        // Saving the currently live conversation reference..
        liveSession = conversation->ref();
        liveSession.fetch();

  // -----------------------------------------------

        if (!liveSession->GetParticipants(liveSession->callerList, Conversation::OTHER_CONSUMERS)) throw SkypeException("Can't obtain participants.\n");
        SEString peopleCalling[liveSession->callerList.size()];

        for (uint i = 0; i < liveSession->callerList.size(); i++)
        {
            //Añadir conversaciones a la tabla. Luego cuando se quiera aceptar uno, obtener la conversacion por ID y hacerle un JoinLiveSession
            peopleCalling[i] = (const char*)liveSession->callerList[i]->GetProp(Participant::P_IDENTITY);

            wxString aux(std::string(peopleCalling[i]).c_str(), wxConvUTF8);

            std::string s_aux = (liveStatus == Conversation::RINGING_FOR_ME)?"Calling":"Call finished";
            wxString aux2(s_aux.c_str(), wxConvUTF8);

            time_t mytime = time(0);
            wxString aux3(std::string(asctime(localtime(&mytime))).c_str(), wxConvUTF8);
            /*
            incoming_calls->ClearAll();
            long itemIndex = incoming_calls->InsertItem(0, aux);

            incoming_calls->SetItem(itemIndex, 1, aux2);
            incoming_calls->SetItem(itemIndex, 2, aux3);

            */

            //TODO: NINONI
            std::string auxiliar;
            auxiliar = "";
            auxiliar.append(std::string(peopleCalling[i]).c_str());
            auxiliar.append(" - ");
            auxiliar.append(s_aux.c_str());
            auxiliar.append(" - ");
            auxiliar.append(std::string(asctime(localtime(&mytime))).c_str());

            incomingCall_event = true;
            incomingCall_message = auxiliar;//std::string(peopleCalling[i]).c_str();


        };

        if (!liveSession->GetParticipants(liveSession->callerList, Conversation::ALL)) throw SkypeException("Can't obtain participants.\n");
        fetch(liveSession->callerList);
  // -----------------------------------------------
    };
  };
};

bool MySkype::SetupAudioDevices(uint micIdx, uint spkIdx){

  SEStringList spkHandles, spkNames, spkProductIDs;
  SEStringList micHandles, micNames, micProductIDs;

  if (!GetAvailableOutputDevices (spkHandles, spkNames,  spkProductIDs)) throw SkypeException("Can't obtain available output devices.\n");
  if (!GetAvailableRecordingDevices (micHandles, micNames, micProductIDs)) throw SkypeException("Can't obtain available recording revices.\n");

  if (micIdx > (micHandles.size() + 1))
  {
    printf("[SKYPE]: Invalid mic device no. (%d) passed to MySkype::SetupAudioDevices\n", micIdx);
    throw SkypeException("Invalid mic device passed to MySkype::SetupAudioDevices.\n");
  };

  if (spkIdx > (spkHandles.size() + 1))
  {
    printf("[SKYPE]: Invalid speaker device no. (%d) passed to MySkype::SetupAudioDevices\n", spkIdx);
    throw SkypeException("Invalid speaker device passed to MySkype::SetupAudioDevices.\n");
  };

  printf("[SKYPE]: Setting mic to %s\n", (const char*)micNames[micIdx]);
  printf("[SKYPE]: Setting speakers to %s\n", (const char*)spkNames[spkIdx]);

  if (!SelectSoundDevices(micHandles[micIdx], spkHandles[spkIdx], spkHandles[spkIdx])) throw SkypeException("Can't select sound devices.\n");
  if (!SetSpeakerVolume(100)) throw SkypeException("Can't set speker volume.\n");
  return true;
}



//MYACCOUNT
MyAccount::MyAccount(unsigned int oid, SERootObject* root) : Account(oid, root){

  loggedIn = false;
  loggedOut = false;
}

void MyAccount::OnChange(int prop){
  // Here we are swicthing loggedIn and loggedOut bools to inform our
  // "main loop" of the account status changes.

  if (prop == Account::P_STATUS)
  {
    // OnChange callback does not directly give you the new value
    // for the property that changed. You will need to explicitly
    // retrieve the new value.
    Account::STATUS loginStatus;
    if (!GetPropStatus(loginStatus)) throw SkypeException("Can't obtain login status.\n");
    if (loginStatus == Account::LOGGED_IN)
    {
      printf("[SKYPE]: Login complete.\n");
      loggedIn = true;
    }
    else if (loginStatus == Account::LOGGED_OUT)
    {
      // Account can proceed to LOGGED_OUT not only on because of intentional logout.
      // This state is also reached by failure conditions, such as invalid password, etc.
      // For this reason, it makes sense to also check the value of Account::P_LOGOUTREASON
      // property.
      Account::LOGOUTREASON whyLogout;
      if (!GetPropLogoutreason(whyLogout)) throw SkypeException("Can't obtain logout reason.\n");

      // The tostring function conveniently converts an SkypeKit enum value
      // to an SEString in following format: <Class>::<ENUMERATOR>.<ENUM>
      // For example: "Account::LOGOUTREASON.INCORRECT_PASSWORD"
      printf("[SKYPE]: %s\n", (const char*)tostring(whyLogout));

      loggedOut = true;
      printf("[SKYPE]: Logout complete.\n");
    };
  };
}



//MYCONTACT
void MyContact::OnChange(int prop){

  if (prop == Contact::P_AVAILABILITY)
  {
    SEString name;
    if (!GetPropDisplayname(name)) throw SkypeException("Can't obtain display name.\n");

    Contact::AVAILABILITY availability;
    if (!GetPropAvailability(availability)) throw SkypeException("Can't obtain availability status.\n");

    SEString statusAsText;
    statusAsText = tostring(availability);

    printf("[SKYPE]: %s -> %s\n", (const char*)name, (const char*)statusAsText);
  };
}



//MYCONTACTGROUP
void MyContactGroup::OnChange(const ContactRef& contact){

  ContactGroup::TYPE groupType;
  if (!GetPropType(groupType)) throw SkypeException("Can't obtain group type.\n");

  if (groupType == ContactGroup::SKYPE_BUDDIES)
  {
    SEString contactName;
    if (!contact->GetPropDisplayname(contactName)) throw SkypeException("Can't obtain contact name.\n");

    if (!contactList.contains(contact))
    {
      contactList.append(contact);
      contact.fetch();
      printf("[SKYPE]: %s was added.\n", (const char*)contactName);
    }
    else
    {
      contactList.remove_val(contact);
      printf("[SKYPE]: %s was removed.\n", (const char*)contactName);
    };
  };
}



//MYPARTICIPANT
void MyParticipant::OnChange(int prop){

  if (prop == Participant::P_SOUND_LEVEL)
  {
    SEString name;
    uint soundLevel;
    if (!GetPropIdentity(name)) throw SkypeException("Can't obtain contact id.\n");
    if (!GetPropSoundLevel(soundLevel)) throw SkypeException("Can't obtain sound level.\n");

    printf("[SKYPE]: %s sound level = %d\n", (const char*)name, soundLevel);
  };
};


