#include "../include/Events.hpp"

/*FGEventGest constructEvtGest(FGEventMessage evtMsg, FGWin handle, FGBool evtPermit)
{
	FGEventGest res;
	
	#if defined(WINDOWS)
		res.evtMsg = evtMsg;
		res.handle = handle;
		evtPermit = evtPermit;
	#elif defined(LINUX)
		evtMsg = evtMsg;
		handle = handle;
		res.evtPermit = evtPermit;
	#endif
	
	return res;
}

FGBool eventGestion(FGEventGest evtGest)
{
	#if defined(WINDOWS)
		return GetMessage(*//*&*//*evtGest.evtMsg, evtGest.handle, evtGest.wMsgFilterMin, evtGest.wMsgFilterMax);
	#elif defined(LINUX)
		return evtGest.isEventPermitted;
	#endif
}

void prepareToEvents(FGEventGest evtGest)
{
	#if defined(WINDOWS)
		TranslateMessage(evtGest.evtMsg);
		DispatchMessage(evtGest.evtMsg);
	#elif defined(LINUX)
		evtGest.isEventPermitted = evtGest.isEventPermitted;
	#endif
}*/