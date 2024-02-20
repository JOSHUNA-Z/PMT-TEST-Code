void ChainSim(TChain* chain){
    
    double DCR, Voltage;
    double mean;
    Int_t n =0;

        //==========loading root File==========

    
    //TChain *chain = new TChain("da");
    
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

    /*
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
    chain->Add("1639_30_4760_2_EA3826.root");]
    chain->Add("1640_30_4760_2_EA3826.root");
    chain->Add("1641_30_4760_2_EA3826.root");*/
    

   /*
    chain->Add("1687_52_1977_0_PA1706-215.root");
    chain->Add("1688_52_1977_0_PA1706-215.root");
    chain->Add("1689_52_1977_0_PA1706-215.root");
    chain->Add("1690_52_1977_0_PA1706-215.root");
    chain->Add("1691_52_1977_0_PA1706-215.root");
    chain->Add("1692_52_1977_0_PA1706-215.root");
    chain->Add("1693_52_1977_0_PA1706-215.root");
    chain->Add("1694_52_1977_0_PA1706-215.root");
    chain->Add("1695_52_1977_0_PA1706-215.root");
    chain->Add("1696_52_1977_0_PA1706-215.root");
    chain->Add("1697_52_1977_0_PA1706-215.root");
    chain->Add("1698_52_1977_0_PA1706-215.root");*/

    chain->Add("1687_55_3886_0_EA4582.root");
    chain->Add("1688_55_3886_0_EA4582.root");
    chain->Add("1689_55_3886_0_EA4582.root");
    chain->Add("1690_55_3886_0_EA4582.root");
    chain->Add("1691_55_3886_0_EA4582.root");
    chain->Add("1692_55_3886_0_EA4582.root");
    chain->Add("1693_55_3886_0_EA4582.root");
    chain->Add("1694_55_3886_0_EA4582.root");
    chain->Add("1695_55_3886_0_EA4582.root");
    chain->Add("1696_55_3886_0_EA4582.root");
    chain->Add("1697_55_3886_0_EA4582.root");
    chain->Add("1698_55_3886_0_EA4582.root");

}