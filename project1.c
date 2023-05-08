/*
 ============================================================================
 Name        : project1.c
 Author      : ahmed khaled ahmed
 Version     :
 Copyright   : Your copyright notice
 Description : vehicle control c project
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define on 1
#define off 0
struct vehiclestate{
	int Enginestate ;
	int AC;
	int Vehicle_Speed;
	int Room_Temperature;
	int Engine_Temperature_Controller_State;
	int Engine_Temperature;
	char Traffic_Light_Color;
}myvehicle,*ptr;


char vehiclecontrol [3][35]={"a- Turn on the vehicle engine\n","b- Turn off the vehicle engine\n","c- Quit the system\n"};
char sensorsmenu [4][60]={"a. Turn off the engine\n","b. Set the traffic light color\n","c. Set the room temperature (Temperature Sensor)\n","d. Set the engine temperature (Engine Temperature Sensor)\n"};
void print_vehicle_control(int index);
void print_sensors_menu(int index);
void print_vehicle_state();
void set_vehicle_speed();
void set_room_temprature();
void set_engine_temprature();


int main(void)
{
	ptr=&myvehicle;
while(1)
{
	print_vehicle_control(-1);
	char com;
	scanf(" %c",&com);
	print_vehicle_control(com-'a');
	if(com=='c')
	{
		break;
	}
	else if(com!='a')
	{
		continue;
	}
	else if(com=='a'){ // com = a engine is one
		while(1){
		ptr->Enginestate=on;
		print_sensors_menu(-1);
		char sensorcomm;
		scanf(" %c",&sensorcomm);
		print_sensors_menu(sensorcomm-'a');
		if(sensorcomm=='a')//turn off engine
		{
			ptr->Enginestate=off;
			ptr->AC=off;
			ptr->Engine_Temperature=0;
			ptr->Engine_Temperature_Controller_State=off;
			ptr->Vehicle_Speed=0;
			ptr->Room_Temperature=0;
			break;
		}
		else if(sensorcomm=='b')//set traffic light color
		{
		set_vehicle_speed();//read traffic light and set the speed
		}
		else if(sensorcomm=='c'){//Set the room temperature (Temperature Sensor)
		set_room_temprature();

		}
		else if (sensorcomm=='d')//d. Set the engine temperature (Engine Temperature Sensor)
		{
		set_engine_temprature();
		}
		else
		{
		continue;
		}

		print_vehicle_state();
	}

}
	else {
		continue;
	}

}}
void print_vehicle_control(int index)
{
	if(index!=0&&index!=1&&index!=2)
	{
		int i =0 ;
		for(;i<3;i++)
		{
			printf("%s",vehiclecontrol[i]);
			fflush(NULL);
		}
	}
	else
	{
		printf("%s\n",vehiclecontrol[index]);

		fflush(NULL);
	}

}
void print_sensors_menu(int index)
{

		if(index!=0&&index!=1&&index!=2&&index!=3)
		{
			int i =0 ;
			for(i=0;i<4;i++){
				printf("%s",sensorsmenu[i]);

		}
		}
		else
		{
			printf("%s\n",sensorsmenu[index]);
			fflush(NULL);
		}
		fflush(NULL);


}
void print_vehicle_state()
{
	printf("Engine state is %d \n",ptr->Enginestate);
	printf("AC is %d \n",ptr->AC);
	printf("Vehicle Speed is %d \n",ptr->Vehicle_Speed);
	printf("Room Temperature is %d \n",ptr->Room_Temperature);
	printf("engine Temperature Controller State is %d \n",ptr->Engine_Temperature_Controller_State);
	printf("Engine Temperature %d \n",ptr->Engine_Temperature);
	printf("%s","  \n");
	fflush(NULL);
}
void set_vehicle_speed()
	{

		while(1){

				char trafic_color;
				scanf(" %c",&trafic_color);
				if(trafic_color=='g')
				{
					ptr->Vehicle_Speed=100;
					break;
				}
				else if(trafic_color=='o')
				{
					ptr->Vehicle_Speed=30;
					break;
				}
				else if (trafic_color=='r')
				{
					ptr->Vehicle_Speed=0;
					break;
				}
				else
				{
					printf("wrong input \n")
							;fflush(NULL);
					continue;
				}
				}		
		if(ptr->Vehicle_Speed==30)
		{
			ptr->AC=on;
			ptr->Room_Temperature=(ptr->Room_Temperature*(5/4)+1);
			ptr->Engine_Temperature_Controller_State=1;
			ptr->Engine_Temperature=(ptr->Engine_Temperature*(5/4)+1);
		}
		
	}
void set_room_temprature()
{

	int temperature ;
	scanf("%d",&temperature);
	if(temperature<10)
	{
		ptr->AC=on;
		ptr->Room_Temperature=20;
	}
	else if (temperature>30)
	{
		ptr->AC=on;
		ptr->Room_Temperature=20;
	}
	else
	{
		ptr->Room_Temperature=temperature;
		ptr->AC=off;

	}
}
void set_engine_temprature()
{
		int temperature;
		scanf("%d",&temperature);
		if(temperature<100||temperature>150)
		{
			ptr->Engine_Temperature_Controller_State=on;
			ptr->Engine_Temperature=125;
		}

		else
		{
			ptr->Engine_Temperature_Controller_State=off;
			ptr->Engine_Temperature=temperature;
		}
}

