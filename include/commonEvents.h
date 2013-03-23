#ifndef COMMON_EVENTS_H_
#define COMMON_EVENTS_H_

#include "wx/wxprec.h"

class TimeOffsetChange{

public:
	TimeOffsetChange(int datalogId, int offset) : datalogId(datalogId), offset(offset){}
	int datalogId;
	int offset;
};

class DatalogChannelSelection {

public:
	DatalogChannelSelection(int datalogId, wxString sessionName, wxString channelName) : datalogId(datalogId), sessionName(sessionName), channelName(channelName){}
	wxString ToString(){ return wxString::Format("%s-%s", sessionName.ToAscii(), channelName.ToAscii());}
	int datalogId;
	wxString sessionName;
	wxString channelName;
};


WX_DECLARE_OBJARRAY(DatalogChannelSelection,DatalogChannelSelectionSet);

DECLARE_EVENT_TYPE ( OPTIONS_CHANGED_EVENT, -1 )
DECLARE_EVENT_TYPE ( CONFIG_CHANGED_EVENT, -1 )
DECLARE_EVENT_TYPE ( CONFIG_STALE_EVENT, -1 )
DECLARE_EVENT_TYPE ( WRITE_CONFIG_EVENT, -1 )
DECLARE_EVENT_TYPE ( ADD_NEW_LINE_CHART_EVENT, -1 )
DECLARE_EVENT_TYPE ( ADD_NEW_ANALOG_GAUGE_EVENT, -1 )
DECLARE_EVENT_TYPE ( ADD_NEW_DIGITAL_GAUGE_EVENT, -1 )
DECLARE_EVENT_TYPE ( ADD_NEW_GPS_VIEW_EVENT, -1 )
DECLARE_EVENT_TYPE ( UPDATE_STATUS_EVENT, -1 )
DECLARE_EVENT_TYPE ( UPDATE_ACTIVITY_EVENT, -1 )
DECLARE_EVENT_TYPE ( SEEK_ABS_DATALOG_EVENT, -1 )
DECLARE_EVENT_TYPE ( PLAY_FWD_DATALOG_EVENT, -1 )
DECLARE_EVENT_TYPE ( PLAY_REV_DATALOG_EVENT, -1 )
DECLARE_EVENT_TYPE ( SEEK_FWD_DATALOG_EVENT, -1 )
DECLARE_EVENT_TYPE ( SEEK_REV_DATALOG_EVENT, -1 )
DECLARE_EVENT_TYPE ( PAUSE_DATALOG_EVENT, -1 )
DECLARE_EVENT_TYPE ( JUMP_BEGINNING_DATALOG_EVENT, -1 )
DECLARE_EVENT_TYPE ( JUMP_END_DATALOG_EVENT, -1 )
DECLARE_EVENT_TYPE ( TIME_OFFSET_CHANGED_EVENT, -1 )


enum{
		CONFIG_CHANGED 	= wxID_HIGHEST + 80000,
		OPTIONS_CHANGED,
		CONFIG_STALE,
		WRITE_CONFIG,
		ADD_NEW_LINE_CHART,
		ADD_NEW_ANALOG_GAUGE,
		ADD_NEW_DIGITAL_GAUGE,
		ADD_NEW_GPS_VIEW,
		UPDATE_STATUS,
		UPDATE_ACTIVITY,
		PLAY_FWD_DATALOG,
		PLAY_REV_DATALOG,
		PAUSE_DATALOG,
		SEEK_ABS_DATALOG,
		JUMP_BEGINNING_DATALOG,
		JUMP_END_DATALOG,
		SEEK_FWD_DATALOG,
		SEEK_REV_DATALOG,
		TIME_OFFSET_CHANGED
};

class ProgressReceiver{
public:
	virtual void OnProgress(int pct) = 0;

	virtual ~ProgressReceiver(){}
};

#endif /*EVENTS_H_*/
