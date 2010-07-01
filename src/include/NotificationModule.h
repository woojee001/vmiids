/*
 * NotificationModule.h
 *
 *  Created on: Jun 26, 2010
 *      Author: kittel
 */

#ifndef NOTIFICATIONMODULE_H_
#define NOTIFICATIONMODULE_H_

#include <string>

class NotificationModule{
	private:
		std::string moduleName;

	public:
		NotificationModule(std::string moduleName){ this->moduleName = moduleName;};
		std::string getName(){ return this->moduleName; };
		virtual void warn(std::string message) = 0;
		virtual void info(std::string message) = 0;
		virtual void debug(std::string message) = 0;
		virtual void error(std::string message) = 0;
		virtual void critical(std::string message) = 0;
};

#include "VmiIDS.h"

#define ADDDYNAMICNOTIFICATIONMODULE_H_(classname, line) class CONCAT(proxy, line) { \
	public: \
	CONCAT(proxy, line)(){ VmiIDS::getInstance()->enqueueNotificationModule(new classname);  } \
}; \
static CONCAT(proxy, line) CONCAT(p, line);

#endif /* NOTIFICATIONMODULE_H_ */