#ifndef CIRCUIT_H
#define CIRCUIT_H
#include <vector>

#include "../heap.h"
#include "event.h"
#include "gate.h"

class Circuit 
{
	public:
		Circuit();
		~Circuit();
		void test();
		bool advance(std::ostream&);
		void run(std::ostream&);
    bool parse(const char*);
    void startUml(std::ostream&);
    void endUml(std::ostream&);
		
	private:
		uint64_t m_current_time;
    std::vector<Gate*> m_gates;
    std::vector<Wire*> m_wires;
		// we need to add the m_pq data member. It should be a min-heap of Event*;
<<<<<<< HEAD
    Heap<Event*, EventLess> m_pq; 
=======
		Heap<Event*, EventLess> m_pq;
        
>>>>>>> 259bfe0f9516f8ad4b0c64298908a8ba0973172b
};

#endif
