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

double MyFitFun1( double *x, double *par );
double MyFitFun3( double *h, double *param );
//double MyFitFun2( double *y, double *pare);

void sim()
{
    double DCR, Voltage;
    double mean;
    Int_t n =0;
    //==========loading root File==========

    
    TChain *chain = new TChain("da");
    
    /*
    chain->Add("1593_14_964_1_PA1706-585.root");
    chain->Add("1594_14_964_1_PA1706-585.root");
    chain->Add("1595_14_964_1_PA1706-585.root");
    chain->Add("1596_14_964_1_PA1706-585.root");
    chain->Add("1597_14_964_1_PA1706-585.root");
    chain->Add("1598_14_964_1_PA1706-585.root");
    chain->Add("1599_14_964_1_PA1706-585.root");
    chain->Add("1600_14_964_1_PA1706-585.root");
    chain->Add("1601_14_964_1_PA1706-585.root");
    chain->Add("1602_14_964_1_PA1706-585.root");
    chain->Add("1603_14_964_1_PA1706-585.root");
    chain->Add("1604_14_964_1_PA1706-585.root");
    chain->Add("1605_14_964_1_PA1706-585.root");
    chain->Add("1606_14_964_1_PA1706-585.root");
    chain->Add("1607_14_964_1_PA1706-585.root");
    chain->Add("1667_14_964_1_PA1706-585.root");
    chain->Add("1668_14_964_1_PA1706-585.root");
    chain->Add("1669_14_964_1_PA1706-585.root");
    chain->Add("1670_14_964_1_PA1706-585.root");
    chain->Add("1671_14_964_1_PA1706-585.root");
    chain->Add("1672_14_964_1_PA1706-585.root");
    */

    /*
    chain->Add("1608_14_964_1_PA1706-585.root");
    chain->Add("1609_14_964_1_PA1706-585.root");
    chain->Add("1610_14_964_1_PA1706-585.root");
    chain->Add("1611_14_964_1_PA1706-585.root");
    chain->Add("1612_14_964_1_PA1706-585.root");
    chain->Add("1613_14_964_1_PA1706-585.root");
    chain->Add("1614_14_964_1_PA1706-585.root");
    chain->Add("1615_14_964_1_PA1706-585.root");
    chain->Add("1616_14_964_1_PA1706-585.root");
    chain->Add("1617_14_964_1_PA1706-585.root");
    chain->Add("1618_14_964_1_PA1706-585.root");
    chain->Add("1619_14_964_1_PA1706-585.root");
    chain->Add("1620_14_964_1_PA1706-585.root");
    chain->Add("1621_14_964_1_PA1706-585.root");
    chain->Add("1622_14_964_1_PA1706-585.root");
    chain->Add("1663_14_964_1_PA1706-585.root");
    chain->Add("1664_14_964_1_PA1706-585.root");
    chain->Add("1665_14_964_1_PA1706-585.root");
    chain->Add("1666_14_964_1_PA1706-585.root");*/

    
    
    /*
    chain->Add("1593_30_4760_2_PA1905-6009.root");
    chain->Add("1594_30_4760_2_PA1905-6009.root");
    chain->Add("1595_30_4760_2_PA1905-6009.root");
    chain->Add("1596_30_4760_2_PA1905-6009.root");
    chain->Add("1597_30_4760_2_PA1905-6009.root");
    chain->Add("1598_30_4760_2_PA1905-6009.root");
    chain->Add("1599_30_4760_2_PA1905-6009.root");
    chain->Add("1600_30_4760_2_PA1905-6009.root");
    chain->Add("1601_30_4760_2_PA1905-6009.root");
    chain->Add("1602_30_4760_2_PA1905-6009.root");
    chain->Add("1603_30_4760_2_PA1905-6009.root");
    chain->Add("1604_30_4760_2_PA1905-6009.root");
    chain->Add("1605_30_4760_2_PA1905-6009.root");
    chain->Add("1606_30_4760_2_PA1905-6009.root");
    chain->Add("1607_30_4760_2_PA1905-6009.root");
    chain->Add("1667_30_4760_2_PA1905-6009.root");
    chain->Add("1668_30_4760_2_PA1905-6009.root");
    chain->Add("1669_30_4760_2_PA1905-6009.root");
    chain->Add("1670_30_4760_2_PA1905-6009.root");
    chain->Add("1671_30_4760_2_PA1905-6009.root");
    chain->Add("1672_30_4760_2_PA1905-6009.root");*/
    

    /*
    chain->Add("1608_30_4760_2_PA1905-6009.root");
    chain->Add("1609_30_4760_2_PA1905-6009.root");
    chain->Add("1610_30_4760_2_PA1905-6009.root");
    chain->Add("1611_30_4760_2_PA1905-6009.root");
    chain->Add("1612_30_4760_2_PA1905-6009.root");
    chain->Add("1613_30_4760_2_PA1905-6009.root");
    chain->Add("1614_30_4760_2_PA1905-6009.root");
    chain->Add("1615_30_4760_2_PA1905-6009.root");
    chain->Add("1616_30_4760_2_PA1905-6009.root");
    chain->Add("1617_30_4760_2_PA1905-6009.root");
    chain->Add("1618_30_4760_2_PA1905-6009.root");
    chain->Add("1619_30_4760_2_PA1905-6009.root");
    chain->Add("1620_30_4760_2_PA1905-6009.root");
    chain->Add("1621_30_4760_2_PA1905-6009.root");
    chain->Add("1622_30_4760_2_PA1905-6009.root");
    chain->Add("1663_30_4760_2_PA1905-6009.root");
    chain->Add("1664_30_4760_2_PA1905-6009.root");
    chain->Add("1665_30_4760_2_PA1905-6009.root");
    chain->Add("1666_30_4760_2_PA1905-6009.root");*/
    
    /*
    chain->Add("1627_14_964_1_EA5215.root");
    chain->Add("1628_14_964_1_EA5215.root");
    chain->Add("1629_14_964_1_EA5215.root");
    chain->Add("1630_14_964_1_EA5215.root");
    chain->Add("1631_14_964_1_EA5215.root");
    chain->Add("1632_14_964_1_EA5215.root");
    chain->Add("1633_14_964_1_EA5215.root");
    chain->Add("1634_14_964_1_EA5215.root");
    chain->Add("1635_14_964_1_EA5215.root");
    chain->Add("1636_14_964_1_EA5215.root");
    chain->Add("1637_14_964_1_EA5215.root");
    chain->Add("1638_14_964_1_EA5215.root");
    chain->Add("1639_14_964_1_EA5215.root");
    chain->Add("1640_14_964_1_EA5215.root");
    chain->Add("1641_14_964_1_EA5215.root");*/
    



    /*
    chain->Add("1642_14_964_1_EA5215.root");
    chain->Add("1643_14_964_1_EA5215.root");
    chain->Add("1644_14_964_1_EA5215.root");
    chain->Add("1645_14_964_1_EA5215.root");
    chain->Add("1646_14_964_1_EA5215.root");
    chain->Add("1647_14_964_1_EA5215.root");
    chain->Add("1648_14_964_1_EA5215.root");
    chain->Add("1649_14_964_1_EA5215.root");
    chain->Add("1650_14_964_1_EA5215.root");
    chain->Add("1651_14_964_1_EA5215.root");
    chain->Add("1652_14_964_1_EA5215.root");
    chain->Add("1653_14_964_1_EA5215.root");
    chain->Add("1654_14_964_1_EA5215.root");        
    chain->Add("1655_14_964_1_EA5215.root");
    chain->Add("1656_14_964_1_EA5215.root");
    chain->Add("1657_14_964_1_EA5215.root");
    chain->Add("1658_14_964_1_EA5215.root");
    chain->Add("1659_14_964_1_EA5215.root");
    chain->Add("1660_14_964_1_EA5215.root");
    chain->Add("1661_14_964_1_EA5215.root");
    chain->Add("1662_14_964_1_EA5215.root");*/

    


    /*
    chain->Add("1642_30_4760_2_EA3826.root");
    chain->Add("1643_30_4760_2_EA3826.root");
    chain->Add("1644_30_4760_2_EA3826.root");    
    chain->Add("1645_30_4760_2_EA3826.root");
    chain->Add("1646_30_4760_2_EA3826.root");
    chain->Add("1647_30_4760_2_EA3826.root");
    chain->Add("1648_30_4760_2_EA3826.root");
    chain->Add("1649_30_4760_2_EA3826.root");
    chain->Add("1650_30_4760_2_EA3826.root");
    chain->Add("1651_30_4760_2_EA3826.root");
    chain->Add("1652_30_4760_2_EA3826.root");
    chain->Add("1653_30_4760_2_EA3826.root");
    chain->Add("1654_30_4760_2_EA3826.root");
    chain->Add("1655_30_4760_2_EA3826.root");
    chain->Add("1656_30_4760_2_EA3826.root");
    chain->Add("1657_30_4760_2_EA3826.root");
    chain->Add("1658_30_4760_2_EA3826.root");
    chain->Add("1659_30_4760_2_EA3826.root");
    chain->Add("1660_30_4760_2_EA3826.root");
    chain->Add("1661_30_4760_2_EA3826.root");
    chain->Add("1662_30_4760_2_EA3826.root");*/

    chain->Add("1627_30_4760_2_EA3826.root");
    chain->Add("1628_30_4760_2_EA3826.root");
    chain->Add("1629_30_4760_2_EA3826.root");
    chain->Add("1630_30_4760_2_EA3826.root");
    chain->Add("1631_30_4760_2_EA3826.root");
    chain->Add("1632_30_4760_2_EA3826.root");
    chain->Add("1633_30_4760_2_EA3826.root");
    chain->Add("1634_30_4760_2_EA3826.root");
    chain->Add("1635_30_4760_2_EA3826.root");
    chain->Add("1636_30_4760_2_EA3826.root");
    chain->Add("1637_30_4760_2_EA3826.root");
    chain->Add("1638_30_4760_2_EA3826.root");
    chain->Add("1639_30_4760_2_EA3826.root");
    chain->Add("1640_30_4760_2_EA3826.root");
    chain->Add("1641_30_4760_2_EA3826.root");
    


    chain->SetBranchAddress( "DCR", &DCR);
    chain->SetBranchAddress( "Voltage", &Voltage);

    //========= Create Canvas ===========
    TCanvas *canvas = new TCanvas( "c1","This is Test Canvs ", 2000, 3000 );
    canvas->Divide( 2, 1);
    canvas->cd(1);
    
    TProfile *result = new TProfile(" h1 ", " DCR vs Voltage ", 15, 1275, 2025);

    //==========Iterate over events===========
    double count_number = 0;
    double count = 0;
    Long64_t nentries = chain->GetEntries();
    cout << " nentries: " << nentries << endl;

    //========== Directly fill ==============
    for( Long64_t jentry =0; jentry< nentries; jentry++)
    {
        chain->GetEntry(jentry);
        
        if( DCR != -1)
        {

            result ->Fill( Voltage, DCR);
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
    result->Fit("myfit","R+");
    
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


}*/# PMT-TEST-Code
# PMT-TEST-Code
# PMT-TEST-Code
