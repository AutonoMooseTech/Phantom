#ifndef ROBOTBASE_H
#define ROBOTBASE_H

#include "Phantom.h"

namespace Phantom {
	class RobotBase {
	public:
		RobotBase();

		enum state_t {DISABLED, ENABLED};

		void enable();
		void disable();
		void setState(state_t state);

		state_t getState();

		bool stateChanged();

		virtual void setup();
		virtual void loop();
		virtual void disabledSetup();
		virtual void disabledLoop();
		virtual void enabledSetup();
		virtual void enabledLoop();

		virtual void update();

	private:
		state_t state;
		state_t stateLast;
	};
}

#endif /* ROBOTBASE_H */