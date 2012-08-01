/** \file ProcessManager.h
 * \author Robotnik Automation S.L.L.
 * \version 1.2
 * \date    2012
 *
 * \brief ProcessManager Class
 * 	Clase desarrollada para la gestión de procesos. Permite lanzar, parar, reiniciar los procesos de
 *  forma sencilla.
 * (C) 2012 Robotnik Automation, SLL
*/


#ifndef _PROCESSMANAGER_H
#define _PROCESSMANAGER_H

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <string>


#define PROCESS_OK				0
#define PROCESS_ERROR_FORK		-1
#define PROCESS_ERROR_EXEC		-2
#define PROCESS_ERROR_WAITING	-3
#define PROCESS_RUNNING			-4
#define PROCESS_ERRROR_KILL		-5


//! Class for create and manage processes
class ProcessManager{

private:
	//! PID of all the processes
	pid_t pid_rviz;
    pid_t pid_grasp_simulator;
    pid_t pid_im_moveBase;
	pid_t pid_im_goto;
	pid_t pid_im_distanceViewer;
	pid_t pid_im_camDisplay;
	pid_t pid_im_assistedArmNavigation;
	pid_t pid_skype_runtime;
	pid_t pid_dashboard;
	pid_t pid_interaction_primitives;

public:
	//! Constructor
	ProcessManager(){
        pid_rviz = -1;
        pid_grasp_simulator = -1;
        pid_im_moveBase = -1;
        pid_im_goto = -1;
        pid_im_distanceViewer = -1;
        pid_im_camDisplay = -1;
        pid_im_assistedArmNavigation = -1;
        pid_skype_runtime = -1;
        pid_dashboard = -1;
        pid_interaction_primitives = -1;

	};
	//! Destructor
	~ProcessManager(){};

	//! Creates a new process and exec player server with kanban driver
	int ExecRviz(std::string rviz_config_file_path);
	int ExecInteractionPrimitives();
    int ExecGraspSimulator();
	int ExecIM_goTo();
	int ExecIM_moveBase();
    int ExecIM_distanceViewer();
    int ExecIM_camDisplay();
    int ExecIM_AssistedArmNavigation();
    int ExecSkypeRuntime(std::string skype_runtime_path);
    int ExecDashboard();

	//! Waits for the termination of Kanban
	int WaitRviz();
    int WaitInteractionPrimitives();
    int WaitGraspSimulator();
    int WaitIM_goTo();
	int WaitIM_moveBase();
    int WaitIM_distanceViewer();
    int WaitIM_camDisplay();
    int WaitIM_AssistedArmNavigation();
    int WaitSkypeRuntime();
    int WaitDashboard();

	//! Sends a signal to the process Kanban to finish the execution
	int ExitRviz();
    int ExitInteractionPrimitives();
    int ExitGraspSimulator();
    int ExitIM_goTo();
	int ExitIM_moveBase();
    int ExitIM_distanceViewer();
    int ExitIM_camDisplay();
    int ExitIM_AssistedArmNavigation();
    int ExitSkypeRuntime();
    int ExitDashboard();
    //int ExitSkypeRuntimeVideo();
    int ExitAll();

	//! Kills the process Kanban
	int KillRviz();
    int KillInteractionPrimitives();
    int KillGraspSimulator();
    int KillIM_goTo();
	int KillIM_moveBase();
    int KillIM_distanceViewer();
    int KillIM_camDisplay();
    int KillIM_AssistedArmNavigation();
    int KillSkypeRuntime();
    int KillDashboard();

};

#endif
