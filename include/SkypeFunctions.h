#ifndef SKYPEFUNCTIONS_H
#define SKYPEFUNCTIONS_H

#include <wx/listctrl.h>
#include <wx/textctrl.h>
#include <wx/image.h>
#include <wx/mstream.h>
#include <wx/msgdlg.h>

#include "skype-embedded_2.h"

using namespace Sid;

class SkypeException : public std::exception
{
    protected:
        std::string messageM;

    public:
        SkypeException(std::string message) throw(){ setMessage(message); };
        virtual ~SkypeException() throw (){};

        virtual std::string getMessage(void) throw() { return messageM; }
        virtual void setMessage(std::string message) throw() { messageM = "[SKYPE ERROR]: " + std::string(message); }
};

class MyParticipant : public Participant
{
public:
  typedef DRef<MyParticipant, Participant> Ref;
  typedef DRefs<MyParticipant, Participant> Refs;
  MyParticipant(unsigned int oid, SERootObject* root) : Participant(oid, root) {};

  void OnChange(int prop);
};

class MyConversation : public Conversation
{
public:

  typedef DRef<MyConversation, Conversation> Ref;
  typedef DRefs<MyConversation, Conversation> Refs;
  MyConversation(unsigned int oid, SERootObject* root) : Conversation(oid, root) {};

  MyParticipant::Refs callerList;

  //void OnChange(int prop);
  //void PickUpCall();
};

class MyAccount : public Account
{
public:

  typedef DRef<MyAccount, Account> Ref;
  typedef DRefs<MyAccount, Account> Refs;
  MyAccount(unsigned int oid, SERootObject* root);

  bool loggedIn;
  bool loggedOut;

  void OnChange(int prop);
};

class MyContact : public Contact
{
public:

  typedef DRef<MyContact, Contact> Ref;
  typedef DRefs<MyContact, Contact> Refs;
  MyContact(unsigned int oid, SERootObject* root) : Contact(oid, root) {};

  void OnChange(int prop);
};

class MyContactGroup : public ContactGroup
{
public:

  typedef DRef<MyContactGroup, ContactGroup> Ref;
  typedef DRefs<MyContactGroup, ContactGroup> Refs;
  MyContactGroup(unsigned int oid, SERootObject* root) : ContactGroup(oid, root) {};

  MyContact::Refs contactList;
  virtual void OnChange( const ContactRef& contact );
};

class MySkype : public Skype
{
public:

  bool callFinished;
  bool isLiveSessionUp;
  wxTextCtrl *log;
  wxListCtrl *incoming_calls;


  MySkype() : Skype() {
    callFinished = false;
    isLiveSessionUp = false;
    liveSession = 0;
  };

  Account*      newAccount(int oid) {return new MyAccount(oid, this);}
  ContactGroup* newContactGroup(int oid) {return new MyContactGroup(oid, this);}
  Contact*      newContact(int oid) {return new MyContact(oid, this);}
  Conversation* newConversation(int oid) {return new MyConversation(oid, this);}
  bool SetupAudioDevices(uint MicNr, uint SpkNr);


  MyConversation::Refs inbox;
  MyConversation::Ref liveSession;
  void OnConversationListChange(const ConversationRef &conversation, const Conversation::LIST_TYPE &type, const bool &added);
  void OnMessage(const Message::Ref& message, const bool&, const Message::Ref&, const ConversationRef& conversation);

  void setOutput(wxTextCtrl *tc){ log = tc;}
  void setEventOutput(wxListCtrl *lc){ incoming_calls = lc; }

};


class SkypeFunctions
{
    public:

        struct user_info
        {
            wxImage avatar;
            std::string name;
            std::string location;
        };

        wxTextCtrl *log;
        wxListCtrl *incoming_calls;

        SEString inetAddr;
        uint portNum;
        bool connected;
        long itemIndex;
        bool calling;

        SkypeFunctions();
        virtual ~SkypeFunctions();

        void initialize();
        int connect(wxListCtrl *contactList);
        void disconnect(wxListCtrl *contactList);
        void initCall(std::string selectedContact);
        void initChat();
        void stopCall(Sid::String userName);
        void Delay(int Sec);
        void sendText(std::string selectedContact, std::string text);
        void showContactList(wxListCtrl *contactList);
        bool isCalling();

        user_info getUserInfo(SEString userName);
        void muteMicro(bool action);
        bool isMicroMuted();
        void muteSound(bool action);
        bool isSoundMuted();
        void acceptCall(std::string userName);
        void refuseCall();

        void setEventOutput(wxListCtrl *lc){ incoming_calls = lc; skype->setEventOutput(lc);}
        void setChatOutput(wxTextCtrl *tc){ log = tc; skype->setOutput(tc); }
    protected:


    private:

        MySkype *skype;
        MyAccount::Ref account;
        MyContactGroup::Ref skypeNamesContactGroup;
        MyConversation::Ref conv;

        bool micro_muted;
        bool sound_muted;
};



#endif // SKYPEFUNCTIONS_H
