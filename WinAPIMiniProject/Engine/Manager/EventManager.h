#pragma once

class EventManager : public Singleton<EventManager>
{
private:

	friend class Singleton;
	EventManager() = default;
	~EventManager() = default;

public:

	void CallEvent(EventData _data);
	void FadeEventPush(EventData _data);
	void ProcessEventlist();

private:

	std::queue<EventData> _eventlist;

};

