#include "AnalyzeWaveform.h"
#include "CalculateCharge.h"
#include <TFile.h>
#include <TTree.h>
int Analysis(const char* Filename)
{
    // string Savefile = "bg_PA1704-679_jiangmen_with_M.root";
    // vector<double> test_variant1;
    // vector<double> test_variant2;

    AnalyzeWaveform aw;
    aw.GetFileName(Filename);

    aw.read_data(); 
    string SaveFile = "PA1704-679-Co60-First.root";
    double test_charge22=0;

    TFile *fl = new TFile((SaveFile).c_str(),"recreate");
    TTree *tree = new TTree("tree","backgroud data");

    
    vector<double> test_variant;
    // test_variant=aw.SaveChargeCh0();//SaveChargeCh0 function 
    // test_variant1=aw.SaveChargeCh1();//SaveChargeCh1 function 
    test_variant=aw.SaveChargeCh2();//SaveChargeCh2 function 
    tree->Branch("charge",&test_charge22,"charge/D");
    TCanvas *test=new TCanvas("test","test picture",1000,1000);
    test->Divide(2,2);
    TH1F *testDrawCharge = new TH1F("DrawCharge","test",800,0,20);
    
    // for(double test_charge2:test_variant)
    // {
    //     testDrawCharge->Fill(test_charge2);
    // }
    
    for(int ct;ct<test_variant.size();ct++)
    {
        test_charge22=test_variant[ct];
        tree->Fill();
        testDrawCharge->Fill(test_variant[ct]);
    }
    tree->Write();
    fl->Close();
    cout << " root file has been writen!! " << endl;

    // test->cd(3);
    // testDrawCharge->Draw();
    // CalculateCharge cal;
    // cal.calculate_peak();

    // const char Filename_fe55="/home/joker/PMT_Experiment/Radiation_Experiment/RawData/20240703/21-51-01/rawdata.dat";



    return 0;
}