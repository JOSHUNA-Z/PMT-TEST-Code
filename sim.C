#include <TROOT.h>
#include <TChain.h>
#include <TTree.h>
#include <TFile.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <TH2F.h>
#include <TH1F.h>
#include <TF1.h>
#include <TMath.h>
#include <TSpectrum.h>
#include <TGraph.h>
#include <fstream>
#include <TProof.h>
#include <TProfile.h>
#include <Hoption.h>
#include <TObject.h>
#include "ChainSim.C"


double MyFitFun1( double *x, double *par );
double MyFitFun3( double *h, double *param );
void sim()
{
    double DCR, Voltage;
    double mean;
    Int_t n =0;
    //========= Create Canvas ===========
    TCanvas *canvas = new TCanvas( "c1","This is Test Canvs ", 2000, 3000 );
    canvas->Divide( 2, 1);
    canvas->cd(1);
    
    TProfile *result = new TProfile(" h1 ", " DCR vs Voltage ", 21, 1275, 2325);

    //==========Iterate over events===========
    double count_number = 0;
    double count = 0;
        
    TChain *chain = new TChain( "da" );
    ChainSim(chain);

    Long64_t nentries = chain->GetEntries();
        
    chain->SetBranchAddress( "DCR",&DCR);
    chain->SetBranchAddress( "Voltage", &Voltage);
    chain->GetListOfFiles()->Print();        
    cout << " nentries: " << nentries << endl;

    //========== Directly fill ==============
    for( Long64_t jentry =0; jentry< nentries; jentry++)
    {
        chain->GetEntry(jentry);
        
        if( DCR != -1)
        {

            result->Fill( Voltage, DCR);
        }
    }
    
    cout << " The program over !!!!! " << endl;
    result->SetErrorOption("i");
    result->SetMarkerStyle(20);
    result->SetMarkerSize(1);
    
    
    TF1 *myfit = new TF1( "myfit" , MyFitFun1, 1275, 2325, 3);
    //TF1 *myfit2 = new TF1( "myfit2" , MyFitFun2, 1275, 1650, 2);
    //TF1 *myfit3 = new TF1( "myfit3", MyFitFun3, 1275, 1675, 5);

    myfit->SetParameter( 0, 20000 );
    myfit->SetParameter( 1, 2000 );
    myfit->SetParameter( 2, 200 );
    //myfit->SetParameter( 3, 10 );
   // myfit->SetParameter( 4, 10);

    //myfit2->SetParameter( 0, 100);
    //myfit2->SetParameter( 1, 0.4);

    /*
    myfit3->SetParameter( 0, -2000000);
    myfit3->SetParameter( 1, 7000);
    myfit3->SetParameter( 2, -5);
    myfit3->SetParameter( 3, 0.001);
    myfit3->SetParameter( 4, -5);*/
    //EA-PMT Fit Parameter

    /*
    myfit3->SetParameter( 0, 90000);
    myfit3->SetParameter( 1, -200);
    myfit3->SetParameter( 2, 0.5);
    myfit3->SetParameter( 3, -0.0001);
    myfit3->SetParameter( 4, -0.00000001);*/
    //PA-PMT Parameter

    //result->Fit("myfit2", "R");
    //result->Fit("myfit3", "R");
    //result->Fit("myfit","R+");
    
    //cout << "BinWidth :" << result->GetBinWidth(1) << endl;
    //cout << " last : " << result->GetBinLowEdge(16) << endl;
    gStyle->SetOptStat( kFALSE );
    //gStyle->SetOptFit(1111);
    gPad->SetLogy();
    //gStyle->SetErrorX(0); //Suppress Error bar along X
    
    result->Draw( " E1 && X0 " );


    // Define an exponential function where [0] and [1] are the parameters to be fitted 
    // and 1275 and 2025 are the range to be fitted.
}    
    //======== Fit ============
    double MyFitFun1( double *x, double *par )
    {
        double FitGauss =1.0;
        double arg = 1.0;
        if( par[2]!= 0){ arg = ( x[0]-par[1])/par[2]; }
        FitGauss = par[0] * TMath::Exp( - arg*arg );

        return FitGauss;
    }
    double MyFitFun3( double *h, double *param )
    {
        double FitPoly = 1.0;
        
        FitPoly = param[0] + param[1] * h[0] + param[2] * TMath::Power( h[0], 2) + param[3] * TMath::Power( h[0], 3) + param[4] * TMath::Power( h[0], 4);
        
        return FitPoly;
    }
/*
double MyFitFun1( double *x, double *par )
{
    double FitRes = 1.0;
    double FitExp = 1.0;
    double FitGauss = 1.0;
    double arg = 1.0;
    FitExp = par[0] * exp( x[0]/par[1] );
    if( par[2] != 0 ){ arg = (x[0]-par[3])/par[2] ;}
    FitGauss = par[4] * TMath::Exp( -arg*arg );

    return FitRes = FitExp + FitGauss;
}*/
/*
double MyFitFun2( double *y, double *pare)
{
    double FitLine = 1.0;
    FitLine = pare[0] + y[0] * pare[1];
    return FitLine;


}*/
