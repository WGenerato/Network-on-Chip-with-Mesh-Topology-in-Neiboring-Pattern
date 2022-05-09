// sink.cpp
#include "sink.h"
void sink::receive_data(){
        sc_time timer;
	packet v_packet;
	if ( sclk.event() ) ack_out.write(false);
	if (packet_in.event() ) 
	{ 
		pkt_recv++ ;
		ack_out.write(true);
		v_packet= packet_in.read();
        if (v_packet.h_t == true){
         timer = sc_time_stamp();
cout << " The whole packet was recieved at : "<< timer.to_string() << endl;
cout << "The average time the packet took was : " << timer/5 << endl;
}
		cout << "			New Pkt:  " << (int)v_packet.data<< " is received from source: " << (int)v_packet.id  << " by sink:  " << (int)sink_id.read() << endl;

	}
}
