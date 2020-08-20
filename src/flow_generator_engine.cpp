#include "flow_generator_engine.h"

#include "flow_generator_engine.h"
#include <ctime>

void flow_generator_engine(long flow_timeout,
						   long activity_timeout,
						   int total_flows = 0,
						   std::string file_path,
						   std::vector<basic_packet_info>& buffer) {
	flow_generator flow_gen = flow_generator(true, flow_timeout, activity_timeout);
	int n_valid = 0;
	int n_total = 0;
	int n_discarded = 0;
	long start = std::time(0) * 1000; // time in miliseconds
	for(int i = 0; i < (int)buffer.size(); ++i) {
		try {
			++n_total;
			if(buffer[i].get_id() != -1) {
				flow_gen.add_packet(buffer[i]);
				++n_valid;
			}
			else {
				++n_discarded;
			}
		}
		catch(...) {
			break;
		}
	}

	flow_gen.dump_labeled_current_flow(file_path);
}