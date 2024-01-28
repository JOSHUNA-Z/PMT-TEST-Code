#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <TFile.h>
#include <TTree.h>
#include <TROOT.h>
#include <TChain.h>
#include <TSelector.h>
#include <TMath.h>
#include <TBenchmark.h>
#include <TF1.h>
#include <TObjArray.h>
#include <TCutG.h>

using namespace std;
//option1 is RunNumber, option2 is Voltage
int ana(int option1 , int option2){




 //========================= loading DCR-parameter
 //========================= DCR-file
 
 string RawDate = "/home/joker/PMT-TestFile/PMT-DCR-DATA/";
 
 int temp1;
 int temp2;
 printf(" RunNumber:  %d \n",option1);
 printf(" The Voltage: %d \n", option2);


 //DCRFile_temp.Form("%s%d%s",RawDate,option1,"/30_4760_2_PA1905-6009.txt");
 char buffer[60]; // Define a character array to store the formatted string
 sprintf(buffer, "%d", option1); // Format the value of option1 as a string, store it in the buffer
 
 //string DCRfileName = RawDate + buffer +"/30_4760_2_PA1905-6009.txt";
 //string DCRfileName = RawDate + buffer + "/14_964_1_PA1706-585.txt";
 //string DCRfileName = RawDate + buffer +"/14_964_1_EA5215.txt";
 string DCRfileName = RawDate + buffer + "/30_4760_2_EA3826.txt";

 string DCRFile =buffer;
 //DCRFile= DCRFile+ "_30_4760_2_PA1905-6009";
 //DCRFile = DCRFile + "_14_964_1_PA1706-585";
 //DCRFile = DCRFile + "_14_964_1_EA5215";
 DCRFile = DCRFile + "_30_4760_2_EA3826";
 

 TFile *juno = new TFile((DCRFile+".root").c_str(),"recreate");
 TTree *da = new TTree("da","Experiment data");
 printf("-----loading DCR-file : %s. \n", DCRfileName.c_str());
 ifstream file;
 int i=0;
 double DCR,Voltage;
 
 vector<double>volt;//default voltage
 vector<double>dcr;

 file.open(DCRfileName.c_str());
 if( file.is_open() )
 {
    string a , b, c;
    double d;

    while( file >> a >> b >> c >> d )
    {

        dcr.push_back(d);
        i = i+1;
    }
    
   printf("..done \n"); 
 }
 else{ printf("...fail open \n"); }
 for(int v =0;v<dcr.size();v++)
 {
    volt.push_back(option2);
 }
 file.close();
 //========================Create root file
 
 da->Branch("DCR", &DCR, "DCR/D");
 da->Branch("Voltage", &Voltage, "Voltage/D" );

 for(int number = 0; number < dcr.size();number++)
 {
    DCR = dcr[number];
    Voltage = volt[number];
    //Printf("Voltage %f\n",Voltage);
    da->Fill();
 }
   da ->Write();
   juno ->Close();
   printf("------Finish!!!! \n");

   return 0;
}
