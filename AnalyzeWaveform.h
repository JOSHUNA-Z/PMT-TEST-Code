#ifndef AnalyzeWaveform_h
#define AnalyzeWaveform_h

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <TROOT.h>
#include <stdint.h>
//****parameters for data_read*******
#define BUFFER_LENGTH  10240   //in byte //65844
#define MAX_CHANNEL_NUMBER  5   //16*16*2
#define TIMESTAMP_ELEMENT_NUMBER   5 //totally 5 numbers with each 11bits in 8ns unit

using namespace std;

class AnalyzeWaveform
{
private:
 std::string filename;
 std::stringstream ss;
 std::ifstream file;
 unsigned char residue;

 double risetime_start=0,risetime_end=0;
 double FWHM_start=0,FWHM_end=0;
 double falltime_start=0,falltime_end=0;
 
 const int gain_ch[6][2]={ {0,0},{1,0},{0,1},{1,1},{0,2},{1,2} };
 int Channel_No;
 double Num_records=0;
 double record_size=2032;//total waveform package size 
                         //include head(16 byte),waveform(2000 byte,1000 data points),tail(16 Byte)
//  double residue = 0;
 double packed_waveform = 0;


public:

    void GetFileName(const std::string& filename)
    {
        this->filename = filename;
        // std::ifstream file;
        
        file.open(filename.c_str());    
        if(file.is_open())
        {
            cout << "File is open !!!" <<endl;
        }
        else
        {
            cout << "Error opening file" << endl;
        }
        file.close();
    }

    int get_gain(const int Channel_No,int& gain, int& ch){
        gain=gain_ch[Channel_No][0];
        ch=gain_ch[Channel_No][1];
        return 0;
    }

    void read_data()
    {
        int n_counts=0;
        double baseline_temp=0;
        
        GetFileName(filename);
        cout << "File name is " << filename << endl;
        FILE *fp = fopen(filename.c_str(), "rb");
        if(fp==NULL)
        {
            cout << "Error opening file" << endl;
        }
        else
        {
            cout << "File is open !!!" <<endl;

        }
        //=================== obtain the file size and calculate==================
        //===============================================================================
        fseek(fp, 0, SEEK_END);   // move pointer to the end of file
        long fileSize = ftell(fp); // get the position of pointer
        fseek(fp, 0, SEEK_SET);   // move pointer to the beginning of file
        cout << "File size is " << fileSize<<" Byte" << endl;
        Num_records=fileSize/record_size;
        cout<<"the numbers of waveform are "<<std::fixed << std::setprecision(0)<< Num_records <<endl;
        int  readout_star=0;
        uint32_t star[BUFFER_LENGTH];
        uint32_t size_bytes = 0;
        uint32_t event[BUFFER_LENGTH];
        uint16_t event_short[BUFFER_LENGTH];
        int global_event_ID=0;
        int global_range_ID=0;
        int global_GCUboard_ID=0;
        int global_package_size=0;
        int test_i=0;// waveform
        int event_number_in_file=0;
        int readout_size=0;
        
        
        //
        while(test_i<Num_records)
        {
            test_i=test_i+1;
            size_bytes=4;
            readout_star=fread(event,sizeof(uint32_t),size_bytes,fp); //DAQ save data in 4 bytes

            //**********read head of waveform and save*************
            for(int i=0;i<int(size_bytes);i++)
               {
                event_short[i*2]=(event[i]&0xFFFF);
                // cout<<"raw event_short =" << event_short[i*2] <<endl;
                event_short[i*2]=((event_short[i*2]&0xFF)<<8)+((event_short[i*2]&0xFF00)>>8);
                event_short[i*2+1]=(event[i]&0xFFFF0000)>>16;
                event_short[i*2+1]=((event_short[i*2+1]&0xFF)<<8)+((event_short[i*2+1]&0xFF00)>>8);

                if(event_short[i*2]==0x805A)
                {cout<<"event_short["<<test_i<<"] = "<<event_short[i*2]<<endl;}
                // if(i==0)
                //   {
                //    global_range_ID=((event_short[i*2+1]&0x1));//obtain LSB
                //    cout<<"global_range_ID="<<global_range_ID<<endl;
                //    if( global_range_ID==0)
                //    {
                //   cout<<"global_range_ID="<<global_range_ID<<endl;
                //    }
                //   }
                // if(i==1)
                //   {
                //   global_package_size=event_short[i*2]*8;
                //  cout<<"global_package_size="<<global_package_size<<endl;  
                //   }
                //   cout<<i<<"  event_short[i*2] = " << event_short[i*2]<<"  event_short[i*2+1] ="<< event_short[i*2+1] << endl;
                }

                read
            // if(test_i == 3){ break; }
            break;
        }

        fclose(fp);
    }


};

#endif // AnalyzeWaveform_h

