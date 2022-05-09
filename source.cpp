// source.cpp
#include "source.h"
void source:: func()
	{
	packet v_packet_out;
	v_packet_out.data=1000; // e.g.
	v_packet_out.pkt_clk = '0';  // an imaginary clock for packets
        int des_count;
        sc_time timer;
	while(true)
		{
		wait();
		if(!ach_in.read())
			{
			v_packet_out.data = v_packet_out.data +source_id.read()+ 1  ; // made a desired data
                        for(des_count=0; des_count<15; des_count++){
                           
			v_packet_out.id = source_id.read();
			 v_packet_out.dest = source_id.read()+des_count;											// assign destination
			if(source_id.read()==des_count) 
                  v_packet_out.dest!=des_count;	// prevent from reciving flits by itself 	

}		 
			v_packet_out.pkt_clk= ~v_packet_out.pkt_clk ;  // add an imaginary clock to each flit 
			v_packet_out.h_t=false;
			pkt_snt++;

			if((pkt_snt%5)==0)v_packet_out.h_t=true; // make tail flit (the packet size is 5)
			packet_out.write(v_packet_out);
                        timer=sc_time_stamp();
            cout << " The whole packet was sent at " << timer.to_string() << endl;
			cout << "New Pkt: " << v_packet_out.data << " is sent by source: " << source_id.read()  << "  to Destination:   "<< v_packet_out.dest <<endl;
exclode:;
			}  
		}
	}
