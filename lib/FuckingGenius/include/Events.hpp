#ifndef EVENTS_HPP
#define EVENTS_HPP

#include "Window.hpp"
#include "Types/BasicTypes.hpp"

#if defined(WINDOWS)
	#define EVENT_EXPRESS std::cout << handle << " " << wMsgFilterMin << " " << wMsgFilterMax << std::endl; \
						  TranslateMessage(&evtMsg); \
						  DispatchMessage(&evtMsg);
#elif defined(POSIX)
	#define EVENT_EXPRESS std::cout << evtMsg << " " << handle << " " << wMsgFilterMin << " " << wMsgFilterMax << std::endl;
#endif

//FGBool DLLIMPORT GetMessage(FGEventMessage evtMsg, FGWin handle, FGUint wMsgFilterMin, FGUint wMsgFilterMax);

struct FGEventGest
{
	#if defined(WINDOWS)
		FGEventMessage evtMsg;
		FGWin handle;
		FGUint wMsgFilterMin;
		FGUint wMsgFilterMax;
	#elif defined(LINUX)
		FGBool isEventPermitted;
	#endif
};

/*FGEventGest constructEvtGest(FGEventMessage evtMsg, FGWin handle = NULL, FGBool evtPermit = true);
FGBool eventGestion(FGEventGest evtGest);
void prepareToEvents(FGEventGest evtGest);*/

#endif // EVENTS_HPP