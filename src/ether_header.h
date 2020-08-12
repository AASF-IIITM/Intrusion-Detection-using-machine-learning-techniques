#ifndef ETHER_HEADER_H
#define ETHER_HEADER_H

#include "constants.h"
#include <netinet/in.h>

class ether_header
{
private:
	uint8_t dst_addr[6]; /* destination MAC addresss (6 bytes) */
	uint8_t src_addr[6]; /* source MAC address (6 bytes) */
};

#endif