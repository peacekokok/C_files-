/*
Peace Okoko
Telephone Service C++ Code 
Progam Documentation
Input: Create an array for the items sold: Iphone
										   galaxy
										   total
										   amount galaxy
										   amount iphone
										   
											
							
Processing: Calculate the amount from iphone sales
			Calculate the amount from galaxy sales
			Calculate the total from both sales
			Calculate the items sold
Output:		Display the week day
			Display the number of iphones sold
			Display the number pf galaxys sold
			Displa the iphone sales
			Display the galaxy sales 
			Display the total from both galaxy and iphone sales
*/


#include<iostream>

#include <iomanip>

using namespace std;

//Golobal Declaration
//Consants
 const float IPHONEPRICE=675.50,
 
             GALAXYPRICE=650.25;

int main()
{
    //Local Declaration
 const int SIZE=7;
       int items_sold[SIZE],
       
       	   week_Day[SIZE]={1,2,3,4,5,6,7},
       
           iphone_sold[SIZE]={5,4,6,3,7,4,2},
           
           galaxy_sold[SIZE]={4,6,5,5,8,4,3};
           
       float salesAmount_galaxy[SIZE],
       
             salesAmount_iphone[SIZE],
             
             totalAmount_sold[SIZE];
             
        cout<<fixed<<showpoint<<setprecision(2);
        
        cout<<setw(9)<<"\nWeek Day"<<setw(15)<<"# Iphone Sold "<<setw(15)<<"# Galaxy Sold"<<setw(15)<<"Iphone Sales"<<setw(15)
	
		<<"Galaxy Sales"<<setw(15)<<"Day Sales"<<endl;
	
	 	cout<<setw(9)<<"\n--------"<<setw(15)<<"-----------"<<setw(15)<<"-------------"<<setw(15)<<"-------------"<<setw(15)
	
		<<"------------"<<setw(15)<<"----------"<<endl;
		 
     //Processing       
    for(int i=0;i< SIZE; i++)
    {
        salesAmount_galaxy[i]= GALAXYPRICE*galaxy_sold[i];
        
        week_Day[i]=week_Day[i];
        
        salesAmount_iphone[i]=IPHONEPRICE*iphone_sold[i];
        
        totalAmount_sold[i]=salesAmount_iphone[i]+salesAmount_galaxy[i];
        
        items_sold[i]=galaxy_sold[i]+iphone_sold[i];
        
        
        
        //Output
	
	
    	cout<<setw(9)<<week_Day[i]<<setw(15)<<iphone_sold[i]<<setw(15)<<galaxy_sold[i]<<setw(15)<<salesAmount_iphone[i]<<setw(15)
	
		<<salesAmount_galaxy[i]<<setw(15)<<totalAmount_sold[i]<<endl;
    }
      
    
    
        return 0;
}
