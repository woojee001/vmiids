/*
 * RkHunterDetectionModule.h
 *
 *  Created on: Jul 2, 2010
 *      Author: kittel
 */

#ifndef RKHUNTERDETECTIONMODULE_H_
#define RKHUNTERDETECTIONMODULE_H_

#include "../notification/ShellNotificationModule.h"
#include "../sensor/QemuMonitorSensorModule.h"
#include "../sensor/FileSystemSensorModule.h"
#include "../sensor/ShellSensorModule.h"

#include <map>
#include <string>

class RkHunterDetectionModule : public DetectionModule {
private:
	NotificationModule * notify;
	QemuMonitorSensorModule * qemu;
	FileSystemSensorModule * fs;
	ShellSensorModule * shell;

	std::multimap<std::string,std::string> rkvars;

	void initializeVariables();

	void performStringCommandCheck();
	void performSharedLibrariesCheck();
	void performFilePropertiesCheck();
	void performKnownRootkitCheck();
	void performAdditionalRootkitCheck();
	void performMalwareCheck();
	void performTrojanSpecificCheck();
	void performLinuxSpecificCheck();
	void performBackdoorCheck();
	void performNetworkInterfacesCheck();
	void performSystemBootCheck();
	void performGroupAndAccountCheck();
	void performSystemConfigurationCheck();
	void performFileSystemCheck();
	void performApplicationVersionsCheck();

public:
	RkHunterDetectionModule();
	virtual ~RkHunterDetectionModule();

	virtual void run();
	virtual void runTime();
	virtual void runEvent();

	virtual void getThreadLevel();
};

#endif /* RKHUNTERDETECTIONMODULE_H_ */
