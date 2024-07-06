#include "AnalyzeWaveform.h"
#include "CalculateCharge.h"
#include <TFile.h>
#include <TTree.h>
#include <TGraph.h>
    
void GetDiff(){
    double test_charge22=0;

    //get bg from root file;
    TH1F *testDrawCharge = new TH1F("DrawCharge","test",800,0,20);
    TChain *chain0 = new TChain( "tree" );
    // chain0->Add("/home/joker/PMT_Experiment/Radiation_Experiment/Armory/fe55_0703_215101.root");
    chain0->Add("/home/joker/PMT_Experiment/Radiation_Experiment/Armory/PA1704-679-Co60.root");
    chain0->SetBranchAddress( "charge",&test_charge22);
    //========= Create Canvas ===========
    TCanvas *canvas = new TCanvas( "c1","Diff", 800, 1000 );
    canvas->Divide(2);
    //==========Iterate over events===========
    Long64_t nentries0 = chain0->GetEntries();
        
    chain0->GetListOfFiles()->Print();  
    
    for( Long64_t jentry =0; jentry< nentries0; jentry++)
    {
        chain0->GetEntry(jentry);
        testDrawCharge->Fill(test_charge22);
    }
    

    // TH1F *result = new TH1F("DrawCharge","test",800,0,20);
    // TChain *chain1 = new TChain( "tree" );
    // // chain1->Add("/home/joker/PMT_Experiment/Radiation_Experiment/Armory/fe55_0703_211549.root");
    
    // chain1->SetBranchAddress( "charge",&test_charge22);
    // //========= Create Canvas ===========

    // //==========Iterate over events===========
    // Long64_t nentries = chain1->GetEntries();
        
    // chain1->GetListOfFiles()->Print();  
    
    // for( Long64_t jentry =0; jentry< nentries; jentry++)
    // {
    //     chain1->GetEntry(jentry);
    //     result->Fill(test_charge22);
    // }


    //==============Get background from no source root file;===============
    TChain *chain = new TChain( "tree" );
    chain->Add("/home/joker/PMT_Experiment/Radiation_Experiment/Armory/test.root");
    chain->SetBranchAddress( "test_charge22",&test_charge22);
    // Int_t n =0;
    //========= Create Canvas ===========
    // TCanvas *canvas = new TCanvas( "c1","Diff", 800, 1000 );
    TH1F *result = new TH1F(" h1 ", " charge_bg ", 800, 0, 20);
     
    //==========Iterate over events===========
    double count_number = 0;
    double count = 0;

    Long64_t nentries = chain->GetEntries();
        
    chain->GetListOfFiles()->Print();  
    
    for( Long64_t jentry =0; jentry< nentries; jentry++)
    {
        chain->GetEntry(jentry);
        result->Fill(test_charge22);
    }

    int underflow_bin = testDrawCharge->GetBin(0); // 下溢出 bin
    int overflow_bin = testDrawCharge->GetBin(801); // 溢出 bin

    std::cout << "fe55 Underflow bin content: " << testDrawCharge->GetBinContent(underflow_bin) << std::endl;
    std::cout << "fe55 Overflow bin content: " << testDrawCharge->GetBinContent(overflow_bin) << std::endl;


    int underflow_bin_bg = result->GetBin(0); // 下溢出 bin
    int overflow_bin_bg = result->GetBin(801); // 溢出 bin

    std::cout << "bg Underflow bin content: " << result->GetBinContent(underflow_bin_bg) << std::endl;
    std::cout << "bg Overflow bin content: " << result->GetBinContent(overflow_bin_bg) << std::endl;

    int total_fe_in_range=nentries0-testDrawCharge->GetBinContent(underflow_bin)-testDrawCharge->GetBinContent(overflow_bin);
    int total_bg_in_range=nentries-result->GetBinContent(underflow_bin_bg)-result->GetBinContent(overflow_bin_bg);

    cout<<"two entries: "<<nentries0<<" "<<nentries<<endl;
    cout<<"two total wave: "<<total_fe_in_range<<" "<<total_bg_in_range<<endl;
    cout<<"two bins length: "<<testDrawCharge->GetNbinsX()<<" "<<result->GetNbinsX()<<endl;

    TH1F *diff_distribute = new TH1F(" diff_distribute ", " diff_distribute ", 50, -0.002, 0.002);
    const int nPoints = 800;
    double y[nPoints];
    double x[nPoints];
    TGraph *graph = new TGraph();

    for (int i = 1; i <= testDrawCharge->GetNbinsX(); ++i) {
        double binContent_fe55 = testDrawCharge->GetBinContent(i);
        double binProbability_fe55 = binContent_fe55 / total_fe_in_range;
        // std::cout << "Bin " << i << ": Probability = " << binProbability << std::endl;
        double binContent_bg = result->GetBinContent(i);
        double binProbability_bg = binContent_bg / total_bg_in_range;
        // std::cout << "Bin " << i << ": Probability = " << binProbability << std::endl;
        y[i] =binProbability_fe55-binProbability_bg;
        // cout<<"diff bin: "<< diff_bin<<endl;
        x[i] = i*1.0/testDrawCharge->GetNbinsX()*20; 
        diff_distribute->Fill(y[i]);
        graph->SetPoint(i, x[i], y[i]);
    }

    graph->SetMarkerStyle(20);
    graph->SetMarkerSize(0.6);
    canvas->cd(1);
    graph->Draw("AP");
    graph->GetXaxis()->SetTitle("PE");
    graph->GetYaxis()->SetTitle("Ratio");
    canvas->cd(2);
    diff_distribute->Draw("same");
    
}