/*
Peace Okoko
CIS 165
Khalil
Progam Documentation
Input: Get customer name
	  Get customer Phone number
	  Get customer plan option
	  Get amount of texts customer sent
Processing: Function to calculate charges
			Function to calculate state tax
			Function to calculate Federal tax
			Function to calculate billl
Output:		Display the State Tax 
			Display the Federal charges
			Display the rate
			Displa the bill
			Display the plan Type 
			Display the numbe of messages sent
*/

	
	#include <iostream>
	#include<iomanip>

	using namespace std;
	
	//Prototype
	
	void getName_Num(string &num, string &name);
	void display_menu(int &planOption, int &messages);
	float getPlanType(string &planType, int messages, int planOption, int rate, int FLATRATE1, int FLATRATE2, int FLATRATE3);
	float calcCharges_text(float charges, int messages, int planOption, float CHARGE, float NUMBERTEXTS1, float NUMBERTEXTS2);
	float calcStateTax(float stateTax, float rate, float charges);
	float calcFedTax(float fedTax, float charges, int rate);
	float calcTbill(float fedTax, float charges, int rate, float stateTax, float tbill);
	//void displayOut( float &stateTax, float &charges, int &rate, float &tbill, string &planType, int &messages);
	void displayOut( float stateTax, float charges, int rate, float tbill, string planType, int messages, string name, string num, float fedTax); 


          //Global Variables (Constants)
			const float STATEFEES=0.07,
                NUMBERTEXTS1=450,
                NUMBERTEXTS2=250,
				CHARGE=0.25,
				FLATRATE1=65,
                FLATRATE2=45,
                FLATRATE3=25,
				FEDERALFEES=0.04;
	int main()
	{ 
		//Local Declaration
  		char 	answer;
  		
  		int     planOption,
		        messages;
    			
    float       totalCharge,
		  		charges,
		  		stateTax,
		  		fedTax,
		  		tbill,
		  		rate;
		  		
		  string num,
		  		 planType,
		  		 name;
		
		
		
		 cout<<fixed<<showpoint<<setprecision(2);
		 
		cout<<"\nDo you want to process a customer (Y=Yes, N= No)(case sensitive):";
		answer=toupper(answer);
		cin>>answer;
		 
		 while(answer=='Y')
	{
	
		//Input Section
         getName_Num(num, name);
           
         display_menu(planOption, messages);
         
         
         
         //Processing Section	
           
         rate =getPlanType(planType, messages, planOption, rate, FLATRATE1, FLATRATE2, FLATRATE3),
           
         charges=calcCharges_text(charges, messages, planOption, CHARGE, NUMBERTEXTS1, NUMBERTEXTS2),
           
        stateTax= calcStateTax(stateTax, rate, charges),
        
        fedTax=calcFedTax(fedTax, charges,rate),
        
        tbill=calcTbill(fedTax, charges, rate, stateTax, tbill);
        
        //Output
        displayOut(stateTax,charges, rate,tbill, planType,messages, name, num, fedTax); 
        
		
		
		
		cout<<"Do you want to process another customer:";
		cin>>answer;
	}
           return 0;
          
	}

	void getName_Num(string &num, string &name)
	{
        cout<<"Enter customer name:";
 
 		cin>>name;
		
		cout<<"Enter customer number:(xxx-xxx-xxxx):";
		
		cin>>num;
	}
	void display_menu(int &planOption, int &messages)
	{
        cout<<"\nUltimate plan gives you unlimited talk, data and text"<<endl;
		
		cout<<"\nDeluxe plan gives you unlimited talk, 3GB of data and 450 free messages"<<endl;
		
		cout<<"\nBasic plan gives you unlimited talk, 1GB of data and 250 free messages"<<endl;
		
		cout<<"\nChoose <1> for Ultimate plan <2> for Deluxe plan <3> for Basic:";
		
		cin>>planOption;
			while (planOption!=1 && planOption!=2 and planOption!=3)
 			{
			 cout<<"\nInvalid selection.\n Choose option (1,2 or 3):";
			 cin>>planOption;
			}
		do
    		{
			cout<<"\nHow many messages did you send?";
			
			cin>>messages;
			
			while(messages > 1500)
			{
			cout<<"\nPlease enter the number of texts between (0-1500):";
			
			cin>>messages;
            }
            
            }
			while ((messages < 0)|| (messages >1501 ));
			
			}
	float getPlanType(string &planType, int messages, int planOption, int rate, int FLATRATE1, int FLATRATE2, int FLATRATE3)
    	{
    	{
		if (planOption==1)
		{
			planType="Ultimate";
			
			rate=FLATRATE1;
			
			cout<<"\nThe price for this plan is"<< rate <<"\nThe plan type is"<< planType;
	
		}
    	else if (planOption==2)
		{
         	planType="Deluxe";
         	
			rate=FLATRATE2;
			 
			cout<<"\nThe price for this plan is: "<< rate <<"\nThe planType is: "<< planType;
		}
    	else 
		{
            planType="Basic";
            
			rate=FLATRATE3;
			cout<<"\nThe price for this plan is: "<<rate <<"\nThe planType is: "<< planType;
	 	}
        
	
	 	}
	
		return rate;
		
	}
	float calcCharges_text(float charges, int messages, int planOption, float CHARGE, float NUMBERTEXTS1, float NUMBERTEXTS2)     
	{
		
		if (planOption==1)
		{
			charges=0;
			
			cout<<"\nYou have no extra charges."<< charges;
		}
	 	else if(planOption==2)
		{
			if(messages<450)
			charges=0;
			else
			{

			charges=CHARGE*(messages-NUMBERTEXTS1);
			
			cout<<"\nYour extra charges are: "<< charges;
			}
			
		}
	
	else
	{
		if(messages<250)
		charges=0;
		else	
		{
		charges=CHARGE*(messages-NUMBERTEXTS2);
		
		cout<<"\nYour extra charges are:"<<charges;
	}
	}
 		return charges;
	}
    
	float calcStateTax(float stateTax, float rate, float charges)
    {
     	stateTax= (rate+charges)*STATEFEES;
		 
		 cout<<"\nYour state tax is: "<<stateTax;
		 
		return stateTax;                  
     }
    float calcFedTax(float fedTax, float charges, int rate)
    {
    	fedTax=FEDERALFEES*(rate+charges);
    
    	cout<<"\nYour Federal tax is:"<<fedTax;
    	
    	return fedTax;
    }
    float calcTbill(float fedTax, float charges, int rate, float stateTax, float tbill)
   {
    tbill=fedTax+rate+charges+stateTax;
    
    	return tbill;
   }
	void displayOut( float stateTax, float charges, int rate, float tbill, string planType, int messages, string name, string num, float fedTax)
   {
   
	cout<<"\n-------------------------"<<"Peace Phone's on the go"<<"----------"<<endl;
	
	cout<<setw(15)<<"Customer Name"<<setw(15)<<"Phone Number"<<setw(15)<<"Plan Type"<<setw(15)
	<<"# Texts"<<endl;
	
	cout<<setw(15)<<name<<setw(15)<<num<<setw(15)<<planType<<setw(15)<<messages<<endl;
	
	cout<<"---------------------------"<<"Bill Details"<<"--------------------"<<endl;
	
	cout<<setw(20)<<"Charges Type"<<setw(20)<<"Amount"<<endl;
	cout<<setw(20)<<"Basic Charges"<<setw(20)<<rate<<endl;
	cout<<setw(20)<<"Text Messages"<<setw(20)<<messages<<endl;
	cout<<setw(20)<<"State Fees"<<setw(20)<<stateTax<<endl;
	cout<<setw(20)<<"Federal Fees"<<setw(20)<<fedTax<<endl;
	cout<<setw(20)<<"Total Bill"<<setw(20)<<tbill<<endl;
    }
