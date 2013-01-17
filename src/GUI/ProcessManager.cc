/** \file ProcessManager.cc
 * \author Robotnik Automation S.L.L.
 * \version 1.1
 * \date    2019
 *
 * \brief ProcessManager Class
 * 	Clase desarrollada para la gestión de procesos de robotrans, pudiendose lanzar, parar, reiniciar los procesos de
 *  forma remota.
 * (C) 2010 Robotnik Automation, SLL
*/
#include "ProcessManager.h"

/*!	\fn int ProcessManager::Exec<PROCESS_NAME>()
 * 	\brief Creates a new process and exec player server with kanban driver
 * 	\return PROCESS_OK
 * 	\return PROCESS_ERROR_FORK
 *	\return PROCESS_ERROR_EXEC
 *	\return PROCESS_ERROR_WAITING
*/

	int ProcessManager::ExecIM_goTo(){
        int status;
        pid_t waitreturnpid;

        if(pid_im_goto > 0){	//Check if it's already running
            waitreturnpid = waitpid(pid_im_goto, &status, WNOHANG);
            if(waitreturnpid == 0){
                printf("ProcessManager::ExecIM_goTo: process already running\n");
                return PROCESS_RUNNING;	//process already running
            }if(waitreturnpid < 0){
                printf("ProcessManager::ExecIM_goTo: Error in waitpid: %s\n", strerror(errno));
                pid_im_goto = -1;
                return PROCESS_ERROR_WAITING;
            }
        }

        if((pid_im_goto = fork()) == -1){
            printf("ProcessManager::ExecIM_goTo: Error in fork: %s\n", strerror(errno));
            return PROCESS_ERROR_FORK; //Error al ejecutar fork
        }else if(pid_im_goto == 0){ //child
            if(execlp("rosrun", "rosrun", "srs_ui_pro", "goto_im", NULL) < 0){
                printf("ProcessManager::ExecIM_goTo: Error in exec: %s\n", strerror(errno));
                return PROCESS_ERROR_EXEC;
            }
        }else{
            return PROCESS_OK;
        }
    }

	int ProcessManager::ExecIM_moveBase(){
        int status;
        pid_t waitreturnpid;

        if(pid_im_moveBase > 0){	//Check if it's already running
            waitreturnpid = waitpid(pid_im_moveBase, &status, WNOHANG);
            if(waitreturnpid == 0){
                printf("ProcessManager::KillIM_moveBase: process already running\n");
                return PROCESS_RUNNING;	//process already running
            }if(waitreturnpid < 0){
                printf("ProcessManager::KillIM_moveBase: Error in waitpid: %s\n", strerror(errno));
                pid_im_moveBase = -1;
                return PROCESS_ERROR_WAITING;
            }
        }

        if((pid_im_moveBase = fork()) == -1){
            printf("ProcessManager::KillIM_moveBase: Error in fork: %s\n", strerror(errno));
            return PROCESS_ERROR_FORK; //Error al ejecutar fork
        }else if(pid_im_moveBase == 0){ //child
            if(execlp("rosrun", "rosrun", "cob_interactive_teleop", "interactive_teleop", NULL) < 0){
                printf("ProcessManager::KillIM_moveBase: Error in exec: %s\n", strerror(errno));
                return PROCESS_ERROR_EXEC;
            }
        }else{
            return PROCESS_OK;
        }
	}

	int ProcessManager::ExecGraspSimulator(){
        int status;
        pid_t waitreturnpid;

        if(pid_grasp_simulator > 0){	//Check if it's already running
            waitreturnpid = waitpid(pid_grasp_simulator, &status, WNOHANG);
            if(waitreturnpid == 0){
                printf("ProcessManager::ExecGraspSimulator: process already running\n");
                return PROCESS_RUNNING;	//process already running
            }if(waitreturnpid < 0){
                printf("ProcessManager::ExecGraspSimulator: Error in waitpid: %s\n", strerror(errno));
                pid_grasp_simulator = -1;
                return PROCESS_ERROR_WAITING;
            }
        }

        if((pid_grasp_simulator = fork()) == -1){
            printf("ProcessManager::ExecGraspSimulator: Error in fork: %s\n", strerror(errno));
            return PROCESS_ERROR_FORK; //Error al ejecutar fork
        }else if(pid_grasp_simulator == 0){ //child
            if(execlp("rosrun", "rosrun", "srs_ui_pro", "grasp_simulator.py", NULL) < 0){
                printf("ProcessManager::ExecGraspSimulator: Error in exec: %s\n", strerror(errno));
                return PROCESS_ERROR_EXEC;
            }
        }else{
            return PROCESS_OK;
        }
    }

	int ProcessManager::ExecIM_distanceViewer(){
        int status;
        pid_t waitreturnpid;

        if(pid_im_distanceViewer > 0){	//Check if it's already running
            waitreturnpid = waitpid(pid_im_distanceViewer, &status, WNOHANG);
            if(waitreturnpid == 0){
                printf("ProcessManager::ExecIM_DistanceViewer: process already running\n");
                return PROCESS_RUNNING;	//process already running
            }if(waitreturnpid < 0){
                printf("ProcessManager::ExecIM_DistanceViewer: Error in waitpid: %s\n", strerror(errno));
                pid_im_distanceViewer = -1;
                return PROCESS_ERROR_WAITING;
            }
        }

        if((pid_im_distanceViewer = fork()) == -1){
            printf("ProcessManager::ExecIM_DistanceViewer: Error in fork: %s\n", strerror(errno));
            return PROCESS_ERROR_FORK; //Error al ejecutar fork
        }else if(pid_im_distanceViewer == 0){ //child
            if(execlp("rosrun", "rosrun", "srs_ui_but", "but_gui_service_server", NULL) < 0){
                printf("ProcessManager::ExecIM_DistanceViewer: Error in exec: %s\n", strerror(errno));
                return PROCESS_ERROR_EXEC;
            }
        }else{
            return PROCESS_OK;
        }
    }

	int ProcessManager::ExecIM_camDisplay(){
        int status;
        pid_t waitreturnpid;

        if(pid_im_camDisplay > 0){	//Check if it's already running
            waitreturnpid = waitpid(pid_im_camDisplay, &status, WNOHANG);
            if(waitreturnpid == 0){
                printf("ProcessManager::ExecIM_camDisplay: process already running\n");
                return PROCESS_RUNNING;	//process already running
            }if(waitreturnpid < 0){
                printf("ProcessManager::ExecIM_camDisplay: Error in waitpid: %s\n", strerror(errno));
                pid_im_camDisplay = -1;
                return PROCESS_ERROR_WAITING;
            }
        }

        if((pid_im_camDisplay = fork()) == -1){
            printf("ProcessManager::ExecIM_camDisplay: Error in fork: %s\n", strerror(errno));
            return PROCESS_ERROR_FORK; //Error al ejecutar fork
        }else if(pid_im_camDisplay == 0){ //child
            if(execlp("rosrun", "rosrun", "srs_ui_but", "data_fusion_view", NULL) < 0){
                printf("ProcessManager::ExecIM_camDisplay: Error in exec: %s\n", strerror(errno));
                return PROCESS_ERROR_EXEC;
            }
        }else{
            return PROCESS_OK;
        }
    }

	int ProcessManager::ExecIM_AssistedArmNavigation(){
        int status;
        pid_t waitreturnpid;

        if(pid_im_assistedArmNavigation > 0){	//Check if it's already running
            waitreturnpid = waitpid(pid_im_assistedArmNavigation, &status, WNOHANG);
            if(waitreturnpid == 0){
                printf("ProcessManager::ExecIM_AssistedArmNavigation: process already running\n");
                return PROCESS_RUNNING;	//process already running
            }if(waitreturnpid < 0){
                printf("ProcessManager::ExecIM_AssistedArmNavigation: Error in waitpid: %s\n", strerror(errno));
                pid_im_assistedArmNavigation = -1;
                return PROCESS_ERROR_WAITING;
            }
        }

        if((pid_im_assistedArmNavigation = fork()) == -1){
            printf("ProcessManager::ExecIM_AssistedArmNavigation: Error in fork: %s\n", strerror(errno));
            return PROCESS_ERROR_FORK; //Error al ejecutar fork
        }else if(pid_im_assistedArmNavigation == 0){ //child
            if(execlp("roslaunch", "roslaunch", "srs_ui_pro", "but_assisted_arm_navigation.launch", NULL) < 0){
                printf("ProcessManager::ExecIM_AssistedArmNavigation: Error in exec: %s\n", strerror(errno));
                return PROCESS_ERROR_EXEC;
            }
        }else{
            return PROCESS_OK;
        }
    }

	int ProcessManager::ExecSkypeRuntime(std::string skype_runtime_path){
        int status;
        pid_t waitreturnpid;

        if(pid_skype_runtime > 0){	//Check if it's already running
            waitreturnpid = waitpid(pid_skype_runtime, &status, WNOHANG);
            if(waitreturnpid == 0){
                printf("ProcessManager::ExecSkypeRuntime: process already running\n");
                return PROCESS_RUNNING;	//process already running
            }if(waitreturnpid < 0){
                printf("ProcessManager::ExecSkypeRuntime: Error in waitpid: %s\n", strerror(errno));
                pid_skype_runtime = -1;
                return PROCESS_ERROR_WAITING;
            }
        }

        if((pid_skype_runtime = fork()) == -1){
            printf("ProcessManager::ExecSkypeRuntime: Error in fork: %s\n", strerror(errno));
            return PROCESS_ERROR_FORK; //Error al ejecutar fork
        }else if(pid_skype_runtime == 0){ //child
            if(execlp(skype_runtime_path.c_str(), NULL) < 0){
                printf("ProcessManager::ExecSkypeRuntime: Error in exec: %s\n", strerror(errno));
                return PROCESS_ERROR_EXEC;
            }
        }else{
            return PROCESS_OK;
        }
    }

	int ProcessManager::ExecDashboard(){
        int status;
        pid_t waitreturnpid;

        if(pid_dashboard > 0){	//Check if it's already running
            waitreturnpid = waitpid(pid_dashboard, &status, WNOHANG);
            if(waitreturnpid == 0){
                printf("ProcessManager::ExecDashboard: process already running\n");
                return PROCESS_RUNNING;	//process already running
            }if(waitreturnpid < 0){
                printf("ProcessManager::ExecDashboard: Error in waitpid: %s\n", strerror(errno));
                pid_dashboard = -1;
                return PROCESS_ERROR_WAITING;
            }
        }

        if((pid_dashboard = fork()) == -1){
            printf("ProcessManager::ExecDashboard: Error in fork: %s\n", strerror(errno));
            return PROCESS_ERROR_FORK; //Error al ejecutar fork
        }else if(pid_dashboard == 0){ //child
            if(execlp("roslaunch", "roslaunch", "cob_bringup", "dashboard.launch", NULL) < 0){
                printf("ProcessManager::ExecDashboard: Error in exec: %s\n", strerror(errno));
                return PROCESS_ERROR_EXEC;
            }
        }else{
            return PROCESS_OK;
        }
    }

	int ProcessManager::ExecInteractionPrimitives(){
        int status;
        pid_t waitreturnpid;

        if(pid_interaction_primitives > 0){	//Check if it's already running
            waitreturnpid = waitpid(pid_interaction_primitives, &status, WNOHANG);
            if(waitreturnpid == 0){
                printf("ProcessManager::ExecInteractionPrimitives: process already running\n");
                return PROCESS_RUNNING;	//process already running
            }if(waitreturnpid < 0){
                printf("ProcessManager::ExecInteractionPrimitives: Error in waitpid: %s\n", strerror(errno));
                pid_interaction_primitives = -1;
                return PROCESS_ERROR_WAITING;
            }
        }

        if((pid_interaction_primitives = fork()) == -1){
            printf("ProcessManager::ExecInteractionPrimitives: Error in fork: %s\n", strerror(errno));
            return PROCESS_ERROR_FORK; //Error al ejecutar fork
        }else if(pid_interaction_primitives == 0){ //child
            if(execlp("rosrun", "rosrun", "srs_interaction_primitives", "interaction_primitives_service_server", NULL) < 0){
                printf("ProcessManager::ExecInteracionPrimitives: Error in exec: %s\n", strerror(errno));
                return PROCESS_ERROR_EXEC;
            }
        }else{
            return PROCESS_OK;
        }
    }

	int ProcessManager::ExecRuntimeMonitor(){
        int status;
        pid_t waitreturnpid;

        if(pid_runtime_monitor > 0){	//Check if it's already running
            waitreturnpid = waitpid(pid_runtime_monitor, &status, WNOHANG);
            if(waitreturnpid == 0){
                printf("ProcessManager::ExecRuntimeMonitor: process already running\n");
                return PROCESS_RUNNING;	//process already running
            }if(waitreturnpid < 0){
                printf("ProcessManager::ExecRuntimeMonitor: Error in waitpid: %s\n", strerror(errno));
                pid_runtime_monitor = -1;
                return PROCESS_ERROR_WAITING;
            }
        }

        if((pid_runtime_monitor = fork()) == -1){
            printf("ProcessManager::ExecRuntimeMonitor: Error in fork: %s\n", strerror(errno));
            return PROCESS_ERROR_FORK; //Error al ejecutar fork
        }else if(pid_runtime_monitor == 0){ //child
            if(execlp("rosrun", "rosrun", "runtime_monitor", "monitor", NULL) < 0){
                printf("ProcessManager::ExecRuntimeMonitor: Error in exec: %s\n", strerror(errno));
                return PROCESS_ERROR_EXEC;
            }
        }else{
            return PROCESS_OK;
        }
    }

	int ProcessManager::ExecRxgraph(){
        int status;
        pid_t waitreturnpid;

        if(pid_rxgraph > 0){	//Check if it's already running
            waitreturnpid = waitpid(pid_rxgraph, &status, WNOHANG);
            if(waitreturnpid == 0){
                printf("ProcessManager::ExecRxgraph: process already running\n");
                return PROCESS_RUNNING;	//process already running
            }if(waitreturnpid < 0){
                printf("ProcessManager::ExecRxgraph: Error in waitpid: %s\n", strerror(errno));
                pid_rxgraph = -1;
                return PROCESS_ERROR_WAITING;
            }
        }

        if((pid_rxgraph = fork()) == -1){
            printf("ProcessManager::ExecRxgraph: Error in fork: %s\n", strerror(errno));
            return PROCESS_ERROR_FORK; //Error al ejecutar fork
        }else if(pid_rxgraph == 0){ //child
            if(execlp("rxgraph", "rxgraph", NULL) < 0){
                printf("ProcessManager::ExecRxgraph: Error in exec: %s\n", strerror(errno));
                return PROCESS_ERROR_EXEC;
            }
        }else{
            return PROCESS_OK;
        }
    }


/*!	\fn int ProcessManager::Wait<PROCESS_NAME>()
 * 	\brief Waits for the termination of TurtleSim
 * 	\return PROCESS_OK
 * 	\return PROCESS_ERROR_WAITING
*/

    int ProcessManager::WaitIM_goTo(){
        pid_t waitreturnpid;
        int status;

        if(pid_im_goto > 0){	//Check if it's already running
            do{
                waitreturnpid = waitpid(pid_im_goto, &status, WNOHANG);
                if(waitreturnpid == 0){
                    //printf("ProcessManager::WaitIM_goTo: Running\n");
                    return PROCESS_RUNNING;
                }

                if(waitreturnpid < 0){
                    //printf("ProcessManager::WaitIM_goTo: Error in waitpid: %s\n", strerror(errno));
                    return PROCESS_ERROR_WAITING;
                }

                if (WIFEXITED(status)) {
                    //printf("ProcessManager::WaitIM_goTo:child exited, status= %d\n", WEXITSTATUS(status));

                } else if (WIFSIGNALED(status)) {
                    //printf("ProcessManager::WaitIM_goTo: child killed (signal %d)\n", WTERMSIG(status));


                } else if (WIFSTOPPED(status)) {
                    //printf("ProcessManager::WaitIM_goTo: child stopped (signal %d)\n", WSTOPSIG(status));
                }

            } while (!WIFEXITED(status) && !WIFSIGNALED(status));

            pid_im_goto = -1;
            return PROCESS_OK;
        }else{
            //printf("ProcessManager::WaitIM_goTo: no process to wait for..\n");
            return PROCESS_OK;
        }
    }

    int ProcessManager::WaitIM_moveBase(){
        pid_t waitreturnpid;
        int status;

        if(pid_im_moveBase > 0){	//Check if it's already running
            do{
                waitreturnpid = waitpid(pid_im_moveBase, &status, WNOHANG);
                if(waitreturnpid == 0){
                    //printf("ProcessManager::WaitIM_moveBase: Running\n");
                    return PROCESS_RUNNING;
                }

                if(waitreturnpid < 0){
                    //printf("ProcessManager::WaitIM_moveBase: Error in waitpid: %s\n", strerror(errno));
                    return PROCESS_ERROR_WAITING;
                }

                if (WIFEXITED(status)) {
                    //printf("ProcessManager::WaitIM_moveBase:child exited, status= %d\n", WEXITSTATUS(status));

                } else if (WIFSIGNALED(status)) {
                    //printf("ProcessManager::WaitIM_moveBase: child killed (signal %d)\n", WTERMSIG(status));


                } else if (WIFSTOPPED(status)) {
                    //printf("ProcessManager::WaitIM_moveBase: child stopped (signal %d)\n", WSTOPSIG(status));
                }

            } while (!WIFEXITED(status) && !WIFSIGNALED(status));

            pid_im_moveBase = -1;
            return PROCESS_OK;
        }else{
            //printf("ProcessManager::WaitIM_moveBase: no process to wait for..\n");
            return PROCESS_OK;
        }
    }

    int ProcessManager::WaitGraspSimulator(){
        pid_t waitreturnpid;
        int status;

        if(pid_grasp_simulator > 0){	//Check if it's already running
            do{
                waitreturnpid = waitpid(pid_grasp_simulator, &status, WNOHANG);
                if(waitreturnpid == 0){
                    //printf("ProcessManager::WaitGraspSimulator: Running\n");
                    return PROCESS_RUNNING;
                }

                if(waitreturnpid < 0){
                    //printf("ProcessManager::WaitGraspSimulator: Error in waitpid: %s\n", strerror(errno));
                    return PROCESS_ERROR_WAITING;
                }

                if (WIFEXITED(status)) {
                    //printf("ProcessManager::WaitGraspSimulator:child exited, status= %d\n", WEXITSTATUS(status));

                } else if (WIFSIGNALED(status)) {
                    //printf("ProcessManager::WaitGraspSimulator: child killed (signal %d)\n", WTERMSIG(status));


                } else if (WIFSTOPPED(status)) {
                    //printf("ProcessManager::WaitGraspSimulator: child stopped (signal %d)\n", WSTOPSIG(status));
                }

            } while (!WIFEXITED(status) && !WIFSIGNALED(status));

            pid_grasp_simulator = -1;
            return PROCESS_OK;
        }else{
            //printf("ProcessManager::WaitGraspSimulator: no process to wait for..\n");
            return PROCESS_OK;
        }
    }

    int ProcessManager::WaitIM_distanceViewer(){
        pid_t waitreturnpid;
        int status;

        if(pid_im_distanceViewer > 0){	//Check if it's already running
            do{
                waitreturnpid = waitpid(pid_im_distanceViewer, &status, WNOHANG);
                if(waitreturnpid == 0){
                    //printf("ProcessManager::WaitIM_distanceViewer: Running\n");
                    return PROCESS_RUNNING;
                }

                if(waitreturnpid < 0){
                    //printf("ProcessManager::WaitIM_distanceViewer: Error in waitpid: %s\n", strerror(errno));
                    return PROCESS_ERROR_WAITING;
                }

                if (WIFEXITED(status)) {
                    //printf("ProcessManager::WaitIM_distanceViewer:child exited, status= %d\n", WEXITSTATUS(status));

                } else if (WIFSIGNALED(status)) {
                    //printf("ProcessManager::WaitIM_distanceViewer: child killed (signal %d)\n", WTERMSIG(status));


                } else if (WIFSTOPPED(status)) {
                    //printf("ProcessManager::WaitIM_distanceViewer: child stopped (signal %d)\n", WSTOPSIG(status));
                }

            } while (!WIFEXITED(status) && !WIFSIGNALED(status));

            pid_im_distanceViewer = -1;
            return PROCESS_OK;
        }else{
            //printf("ProcessManager::WaitIM_distanceViewer: no process to wait for..\n");
            return PROCESS_OK;
        }
    }

    int ProcessManager::WaitIM_camDisplay(){
        pid_t waitreturnpid;
        int status;

        if(pid_im_camDisplay > 0){	//Check if it's already running
            do{
                waitreturnpid = waitpid(pid_im_camDisplay, &status, WNOHANG);
                if(waitreturnpid == 0){
                    //printf("ProcessManager::WaitIM_camDisplay: Running\n");
                    return PROCESS_RUNNING;
                }

                if(waitreturnpid < 0){
                    //printf("ProcessManager::WaitIM_camDisplay: Error in waitpid: %s\n", strerror(errno));
                    return PROCESS_ERROR_WAITING;
                }

                if (WIFEXITED(status)) {
                    //printf("ProcessManager::WaitIM_camDisplay:child exited, status= %d\n", WEXITSTATUS(status));

                } else if (WIFSIGNALED(status)) {
                    //printf("ProcessManager::WaitIM_camDisplay: child killed (signal %d)\n", WTERMSIG(status));


                } else if (WIFSTOPPED(status)) {
                    //printf("ProcessManager::WaitIM_camDisplay: child stopped (signal %d)\n", WSTOPSIG(status));
                }

            } while (!WIFEXITED(status) && !WIFSIGNALED(status));

            pid_im_camDisplay = -1;
            return PROCESS_OK;
        }else{
            //printf("ProcessManager::WaitIM_camDisplay: no process to wait for..\n");
            return PROCESS_OK;
        }
    }

    int ProcessManager::WaitIM_AssistedArmNavigation(){
        pid_t waitreturnpid;
        int status;

        if(pid_im_assistedArmNavigation > 0){	//Check if it's already running
            do{
                waitreturnpid = waitpid(pid_im_assistedArmNavigation, &status, WNOHANG);
                if(waitreturnpid == 0){
                    //printf("ProcessManager::WaitIM_AssistedArmNavigation: Running\n");
                    return PROCESS_RUNNING;
                }

                if(waitreturnpid < 0){
                    //printf("ProcessManager::WaitIM_AssistedArmNavigation: Error in waitpid: %s\n", strerror(errno));
                    return PROCESS_ERROR_WAITING;
                }

                if (WIFEXITED(status)) {
                    //printf("ProcessManager::WaitIM_AssistedArmNavigation:child exited, status= %d\n", WEXITSTATUS(status));

                } else if (WIFSIGNALED(status)) {
                    //printf("ProcessManager::WaitIM_AssistedArmNavigation: child killed (signal %d)\n", WTERMSIG(status));


                } else if (WIFSTOPPED(status)) {
                    //printf("ProcessManager::WaitIM_AssistedArmNavigation: child stopped (signal %d)\n", WSTOPSIG(status));
                }

            } while (!WIFEXITED(status) && !WIFSIGNALED(status));

            pid_im_assistedArmNavigation = -1;
            return PROCESS_OK;
        }else{
            //printf("ProcessManager::WaitIM_AssistedArmNavigation: no process to wait for..\n");
            return PROCESS_OK;
        }
    }

    int ProcessManager::WaitSkypeRuntime(){
        pid_t waitreturnpid;
        int status;

        if(pid_skype_runtime > 0){	//Check if it's already running
            do{
                waitreturnpid = waitpid(pid_skype_runtime, &status, WNOHANG);
                if(waitreturnpid == 0){
                    //printf("ProcessManager::WaitSkypeRuntime: Running\n");
                    return PROCESS_RUNNING;
                }

                if(waitreturnpid < 0){
                    //printf("ProcessManager::WaitSkypeRuntime: Error in waitpid: %s\n", strerror(errno));
                    return PROCESS_ERROR_WAITING;
                }

                if (WIFEXITED(status)) {
                    //printf("ProcessManager::WaitSkypeRuntime:child exited, status= %d\n", WEXITSTATUS(status));

                } else if (WIFSIGNALED(status)) {
                    //printf("ProcessManager::WaitSkypeRuntime: child killed (signal %d)\n", WTERMSIG(status));


                } else if (WIFSTOPPED(status)) {
                    //printf("ProcessManager::WaitSkypeRuntime: child stopped (signal %d)\n", WSTOPSIG(status));
                }

            } while (!WIFEXITED(status) && !WIFSIGNALED(status));

            pid_skype_runtime = -1;
            return PROCESS_OK;
        }else{
            //printf("ProcessManager::WaitSkypeRuntime: no process to wait for..\n");
            return PROCESS_OK;
        }
    }

    int ProcessManager::WaitDashboard(){
        pid_t waitreturnpid;
        int status;

        if(pid_dashboard > 0){	//Check if it's already running
            do{
                waitreturnpid = waitpid(pid_dashboard, &status, WNOHANG);
                if(waitreturnpid == 0){
                    //printf("ProcessManager::WaitDashboard: Running\n");
                    return PROCESS_RUNNING;
                }

                if(waitreturnpid < 0){
                    //printf("ProcessManager::WaitDashboard: Error in waitpid: %s\n", strerror(errno));
                    return PROCESS_ERROR_WAITING;
                }

                if (WIFEXITED(status)) {
                    //printf("ProcessManager::WaitDashboard:child exited, status= %d\n", WEXITSTATUS(status));

                } else if (WIFSIGNALED(status)) {
                    //printf("ProcessManager::WaitDashboard: child killed (signal %d)\n", WTERMSIG(status));


                } else if (WIFSTOPPED(status)) {
                    //printf("ProcessManager::WaitDashboard: child stopped (signal %d)\n", WSTOPSIG(status));
                }

            } while (!WIFEXITED(status) && !WIFSIGNALED(status));

            pid_dashboard = -1;
            return PROCESS_OK;
        }else{
            //printf("ProcessManager::WaitDashboard: no process to wait for..\n");
            return PROCESS_OK;
        }
    }

    int ProcessManager::WaitInteractionPrimitives(){
        pid_t waitreturnpid;
        int status;

        if(pid_interaction_primitives > 0){	//Check if it's already running
            do{
                waitreturnpid = waitpid(pid_interaction_primitives, &status, WNOHANG);
                if(waitreturnpid == 0){
                    //printf("ProcessManager::WaitDashboard: Running\n");
                    return PROCESS_RUNNING;
                }

                if(waitreturnpid < 0){
                    //printf("ProcessManager::WaitDashboard: Error in waitpid: %s\n", strerror(errno));
                    return PROCESS_ERROR_WAITING;
                }

                if (WIFEXITED(status)) {
                    //printf("ProcessManager::WaitDashboard:child exited, status= %d\n", WEXITSTATUS(status));

                } else if (WIFSIGNALED(status)) {
                    //printf("ProcessManager::WaitDashboard: child killed (signal %d)\n", WTERMSIG(status));


                } else if (WIFSTOPPED(status)) {
                    //printf("ProcessManager::WaitDashboard: child stopped (signal %d)\n", WSTOPSIG(status));
                }

            } while (!WIFEXITED(status) && !WIFSIGNALED(status));

            pid_interaction_primitives = -1;
            return PROCESS_OK;
        }else{
            //printf("ProcessManager::WaitDashboard: no process to wait for..\n");
            return PROCESS_OK;
        }
    }

    int ProcessManager::WaitRuntimeMonitor(){
        pid_t waitreturnpid;
        int status;

        if(pid_runtime_monitor > 0){	//Check if it's already running
            do{
                waitreturnpid = waitpid(pid_runtime_monitor, &status, WNOHANG);
                if(waitreturnpid == 0){
                    //printf("ProcessManager::WaitDashboard: Running\n");
                    return PROCESS_RUNNING;
                }

                if(waitreturnpid < 0){
                    //printf("ProcessManager::WaitDashboard: Error in waitpid: %s\n", strerror(errno));
                    return PROCESS_ERROR_WAITING;
                }

                if (WIFEXITED(status)) {
                    //printf("ProcessManager::WaitDashboard:child exited, status= %d\n", WEXITSTATUS(status));

                } else if (WIFSIGNALED(status)) {
                    //printf("ProcessManager::WaitDashboard: child killed (signal %d)\n", WTERMSIG(status));


                } else if (WIFSTOPPED(status)) {
                    //printf("ProcessManager::WaitDashboard: child stopped (signal %d)\n", WSTOPSIG(status));
                }

            } while (!WIFEXITED(status) && !WIFSIGNALED(status));

            pid_runtime_monitor = -1;
            return PROCESS_OK;
        }else{
            //printf("ProcessManager::WaitDashboard: no process to wait for..\n");
            return PROCESS_OK;
        }
    }

    int ProcessManager::WaitRxgraph(){
        pid_t waitreturnpid;
        int status;

        if(pid_rxgraph > 0){	//Check if it's already running
            do{
                waitreturnpid = waitpid(pid_rxgraph, &status, WNOHANG);
                if(waitreturnpid == 0){
                    //printf("ProcessManager::WaitDashboard: Running\n");
                    return PROCESS_RUNNING;
                }

                if(waitreturnpid < 0){
                    //printf("ProcessManager::WaitDashboard: Error in waitpid: %s\n", strerror(errno));
                    return PROCESS_ERROR_WAITING;
                }

                if (WIFEXITED(status)) {
                    //printf("ProcessManager::WaitDashboard:child exited, status= %d\n", WEXITSTATUS(status));

                } else if (WIFSIGNALED(status)) {
                    //printf("ProcessManager::WaitDashboard: child killed (signal %d)\n", WTERMSIG(status));


                } else if (WIFSTOPPED(status)) {
                    //printf("ProcessManager::WaitDashboard: child stopped (signal %d)\n", WSTOPSIG(status));
                }

            } while (!WIFEXITED(status) && !WIFSIGNALED(status));

            pid_rxgraph = -1;
            return PROCESS_OK;
        }else{
            //printf("ProcessManager::WaitDashboard: no process to wait for..\n");
            return PROCESS_OK;
        }
    }


/*!	\fn int ProcessManager::Exit<PROCESS_NAME>()
 * 	\brief Sends a signal to the process TurtleSim to finish the execution
 * 	\return PROCESS_OK
 * 	\return PROCESS_ERRROR_KILL
*/

	int ProcessManager::ExitIM_goTo(){
        if(pid_im_goto > 0){
            if(kill(pid_im_goto, SIGINT)!=0){
                printf("ProcessManager::ExitIM_goTo: Error sending the signal: %s\n", strerror(errno));
                return PROCESS_ERRROR_KILL;
            }else{
                pid_im_goto = -1;
                return PROCESS_OK;
            }
        }else{
            printf("ProcessManager::ExitIM_goTo: process is not running\n");
            return PROCESS_OK;
        }
    }

	int ProcessManager::ExitIM_moveBase(){
        if(pid_im_moveBase > 0){
            if(kill(pid_im_moveBase, SIGINT)!=0){
                printf("ProcessManager::ExitIM_moveBase: Error sending the signal: %s\n", strerror(errno));
                return PROCESS_ERRROR_KILL;
            }else{
                pid_im_moveBase = -1;
                return PROCESS_OK;
            }
        }else{
            printf("ProcessManager::ExitIM_moveBase: process is not running\n");
            return PROCESS_OK;
        }
    }

	int ProcessManager::ExitGraspSimulator(){
        if(pid_grasp_simulator > 0){
            if(kill(pid_grasp_simulator, SIGINT)!=0){
                printf("ProcessManager::ExitGraspSimulator: Error sending the signal: %s\n", strerror(errno));
                return PROCESS_ERRROR_KILL;
            }else{
                pid_grasp_simulator = -1;
                return PROCESS_OK;
            }
        }else{
            printf("ProcessManager::ExitGraspSimulator: process is not running\n");
            return PROCESS_OK;
        }
    }

	int ProcessManager::ExitIM_distanceViewer(){
        if(pid_im_distanceViewer > 0){
            if(kill(pid_im_distanceViewer, SIGINT)!=0){
                printf("ProcessManager::ExitIM_distanceViewer: Error sending the signal: %s\n", strerror(errno));
                return PROCESS_ERRROR_KILL;
            }else{
                pid_im_distanceViewer = -1;
                return PROCESS_OK;
            }
        }else{
            printf("ProcessManager::ExitIM_distanceViewer: process is not running\n");
            return PROCESS_OK;
        }
    }

	int ProcessManager::ExitIM_camDisplay(){
        if(pid_im_camDisplay > 0){
            if(kill(pid_im_camDisplay, SIGINT)!=0){
                printf("ProcessManager::ExitIM_camDisplay: Error sending the signal: %s\n", strerror(errno));
                return PROCESS_ERRROR_KILL;
            }else{
                pid_im_camDisplay = -1;
                return PROCESS_OK;
            }
        }else{
            printf("ProcessManager::ExitIM_camDisplay: process is not running\n");
            return PROCESS_OK;
        }
    }

	int ProcessManager::ExitIM_AssistedArmNavigation(){
        if(pid_im_assistedArmNavigation > 0){
            if(kill(pid_im_assistedArmNavigation, SIGINT)!=0){
                printf("ProcessManager::ExitIM_AssistedArmNavigation: Error sending the signal: %s\n", strerror(errno));
                return PROCESS_ERRROR_KILL;
            }else{
                pid_im_assistedArmNavigation = -1;
                return PROCESS_OK;
            }
        }else{
            printf("ProcessManager::ExitIM_AssistedArmNavigation: process is not running\n");
            return PROCESS_OK;
        }
    }

	int ProcessManager::ExitSkypeRuntime(){
        if(pid_skype_runtime > 0){
            if(kill(pid_skype_runtime, SIGINT)!=0){
                printf("ProcessManager::ExitSkypeRuntime: Error sending the signal: %s\n", strerror(errno));
                return PROCESS_ERRROR_KILL;
            }else{
                pid_skype_runtime = -1;
                return PROCESS_OK;
            }
        }else{
            printf("ProcessManager::ExitSkypeRuntime: process is not running\n");
            return PROCESS_OK;
        }
    }

	int ProcessManager::ExitDashboard(){
        if(pid_skype_runtime > 0){
            if(kill(pid_skype_runtime, SIGINT)!=0){
                printf("ProcessManager::ExitSkypeRuntime: Error sending the signal: %s\n", strerror(errno));
                return PROCESS_ERRROR_KILL;
            }else{
                pid_skype_runtime = -1;
                return PROCESS_OK;
            }
        }else{
            printf("ProcessManager::ExitSkypeRuntime: process is not running\n");
            return PROCESS_OK;
        }
    }

	int ProcessManager::ExitInteractionPrimitives(){
        if(pid_interaction_primitives > 0){
            if(kill(pid_interaction_primitives, SIGINT)!=0){
                printf("ProcessManager::ExitInteractionPrimitives: Error sending the signal: %s\n", strerror(errno));
                return PROCESS_ERRROR_KILL;
            }else{
                pid_interaction_primitives = -1;
                return PROCESS_OK;
            }
        }else{
            printf("ProcessManager::ExitInteractionPrimitives: process is not running\n");
            return PROCESS_OK;
        }
    }

	int ProcessManager::ExitRuntimeMonitor(){
        if(pid_runtime_monitor > 0){
            if(kill(pid_runtime_monitor, SIGINT)!=0){
                printf("ProcessManager::ExitRuntimeMonitor: Error sending the signal: %s\n", strerror(errno));
                return PROCESS_ERRROR_KILL;
            }else{
                pid_runtime_monitor = -1;
                return PROCESS_OK;
            }
        }else{
            printf("ProcessManager::ExitRuntimeMonitor: process is not running\n");
            return PROCESS_OK;
        }
    }

	int ProcessManager::ExitRxgraph(){
        if(pid_rxgraph > 0){
            if(kill(pid_rxgraph, SIGINT)!=0){
                printf("ProcessManager::ExitRxgraph: Error sending the signal: %s\n", strerror(errno));
                return PROCESS_ERRROR_KILL;
            }else{
                pid_rxgraph = -1;
                return PROCESS_OK;
            }
        }else{
            printf("ProcessManager::ExitRxgraph: process is not running\n");
            return PROCESS_OK;
        }
    }

	int ProcessManager::ExitAll(){

	    if (WaitInteractionPrimitives() == -4)
            ExitInteractionPrimitives();

	    if (WaitGraspSimulator() == -4)
            ExitGraspSimulator();

	    if (WaitIM_goTo() == -4)
            ExitIM_goTo();

	    if (WaitIM_moveBase() == -4)
            ExitIM_moveBase();

	    if (WaitIM_distanceViewer() == -4)
            ExitIM_distanceViewer();

	    if (WaitIM_camDisplay() == -4)
            ExitIM_camDisplay();

	    if (WaitIM_AssistedArmNavigation() == -4)
            ExitIM_AssistedArmNavigation();

	    if (WaitSkypeRuntime() == -4)
            ExitSkypeRuntime();

	    if (WaitDashboard() == -4)
            ExitDashboard();

        if (WaitRuntimeMonitor() == -4)
            ExitRuntimeMonitor();

	    if (WaitRxgraph() == -4)
            ExitRxgraph();
	}


/*!	\fn int ProcessManager::Kill<PROCESS_NAME>()
 * 	\brief Kills the process TurtleSim
 * 	\return PROCESS_OK
 * 	\return PROCESS_ERRROR_KILL
*/

	int ProcessManager::KillIM_goTo(){
        if(pid_im_goto > 0){
            if(kill(pid_im_goto, SIGKILL)!=0){
                printf("ProcessManager::KillIM_goTo: Error sending the signal: %s\n", strerror(errno));
                return PROCESS_ERRROR_KILL;
            }else{
                pid_im_goto = -1;
                return PROCESS_OK;
            }
        }else{
            printf("ProcessManager::KillIM_goTo: process is not running\n");
            return PROCESS_OK;
        }
    }

	int ProcessManager::KillIM_moveBase(){
        if(pid_im_moveBase > 0){
            if(kill(pid_im_moveBase, SIGKILL)!=0){
                printf("ProcessManager::KillIM_moveBase: Error sending the signal: %s\n", strerror(errno));
                return PROCESS_ERRROR_KILL;
            }else{
                pid_im_moveBase = -1;
                return PROCESS_OK;
            }
        }else{
            printf("ProcessManager::KillIM_moveBase: process is not running\n");
            return PROCESS_OK;
        }
    }

    int ProcessManager::KillGraspSimulator(){
        if(pid_grasp_simulator > 0){
            if(kill(pid_grasp_simulator, SIGKILL)!=0){
                printf("ProcessManager::KillGraspSimulator: Error sending the signal: %s\n", strerror(errno));
                return PROCESS_ERRROR_KILL;
            }else{
                pid_grasp_simulator = -1;
                return PROCESS_OK;
            }
        }else{
            printf("ProcessManager::KillGraspSimulator: process is not running\n");
            return PROCESS_OK;
        }
    }

	int ProcessManager::KillIM_distanceViewer(){
        if(pid_im_distanceViewer > 0){
            if(kill(pid_im_distanceViewer, SIGKILL)!=0){
                printf("ProcessManager::KillIM_distanceViewer: Error sending the signal: %s\n", strerror(errno));
                return PROCESS_ERRROR_KILL;
            }else{
                pid_im_distanceViewer = -1;
                return PROCESS_OK;
            }
        }else{
            printf("ProcessManager::KillIM_distanceViewer: process is not running\n");
            return PROCESS_OK;
        }
    }

	int ProcessManager::KillIM_camDisplay(){
        if(pid_im_camDisplay > 0){
            if(kill(pid_im_camDisplay, SIGKILL)!=0){
                printf("ProcessManager::KillIM_camDisplay: Error sending the signal: %s\n", strerror(errno));
                return PROCESS_ERRROR_KILL;
            }else{
                pid_im_camDisplay = -1;
                return PROCESS_OK;
            }
        }else{
            printf("ProcessManager::KillIM_camDisplay: process is not running\n");
            return PROCESS_OK;
        }
    }

	int ProcessManager::KillIM_AssistedArmNavigation(){
        if(pid_im_assistedArmNavigation > 0){
            if(kill(pid_im_assistedArmNavigation, SIGKILL)!=0){
                printf("ProcessManager::KillIM_AssistedArmNavigation: Error sending the signal: %s\n", strerror(errno));
                return PROCESS_ERRROR_KILL;
            }else{
                pid_im_assistedArmNavigation = -1;
                return PROCESS_OK;
            }
        }else{
            printf("ProcessManager::KillIM_AssistedArmNavigation: process is not running\n");
            return PROCESS_OK;
        }
    }

	int ProcessManager::KillSkypeRuntime(){
        if(pid_skype_runtime > 0){
            if(kill(pid_skype_runtime, SIGKILL)!=0){
                printf("ProcessManager::KillSkypeRuntime: Error sending the signal: %s\n", strerror(errno));
                return PROCESS_ERRROR_KILL;
            }else{
                pid_skype_runtime = -1;
                return PROCESS_OK;
            }
        }else{
            printf("ProcessManager::KillSkypeRuntime: process is not running\n");
            return PROCESS_OK;
        }
    }

	int ProcessManager::KillDashboard(){
        if(pid_dashboard > 0){
            if(kill(pid_dashboard, SIGKILL)!=0){
                printf("ProcessManager::KillDashboard: Error sending the signal: %s\n", strerror(errno));
                return PROCESS_ERRROR_KILL;
            }else{
                pid_dashboard = -1;
                return PROCESS_OK;
            }
        }else{
            printf("ProcessManager::KillDashboard: process is not running\n");
            return PROCESS_OK;
        }
    }

	int ProcessManager::KillInteractionPrimitives(){
        if(pid_interaction_primitives > 0){
            if(kill(pid_interaction_primitives, SIGKILL)!=0){
                printf("ProcessManager::KillInteractionPrimitives: Error sending the signal: %s\n", strerror(errno));
                return PROCESS_ERRROR_KILL;
            }else{
                pid_interaction_primitives = -1;
                return PROCESS_OK;
            }
        }else{
            printf("ProcessManager::KillInteractionPrimitives: process is not running\n");
            return PROCESS_OK;
        }
    }

	int ProcessManager::KillRuntimeMonitor(){
        if(pid_runtime_monitor > 0){
            if(kill(pid_runtime_monitor, SIGKILL)!=0){
                printf("ProcessManager::KillRuntimeMonitor: Error sending the signal: %s\n", strerror(errno));
                return PROCESS_ERRROR_KILL;
            }else{
                pid_runtime_monitor = -1;
                return PROCESS_OK;
            }
        }else{
            printf("ProcessManager::KillRuntimeMonitor: process is not running\n");
            return PROCESS_OK;
        }
    }

	int ProcessManager::KillRxgraph(){
        if(pid_rxgraph > 0){
            if(kill(pid_rxgraph, SIGKILL)!=0){
                printf("ProcessManager::KillRxgraph: Error sending the signal: %s\n", strerror(errno));
                return PROCESS_ERRROR_KILL;
            }else{
                pid_rxgraph = -1;
                return PROCESS_OK;
            }
        }else{
            printf("ProcessManager::KillRxgraph: process is not running\n");
            return PROCESS_OK;
        }
    }



