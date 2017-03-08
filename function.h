//Init.c
void init();

//service.c
void goin();
void goout();

//Timmer.c
void timmer_park(char carNo[]);
void timmer_out(char carNo[]);
void alter_price();

//PriceCount.c
int priceCount(int secUse); //call by timmer_out()

//Audit.c
void audit();

//ErrorControl.c
int provRePark(char carNo[]);  //call by goin()

//Query.c
int space_query();
void park_query();

//Logout.c 
int Logout();

//Picture.c
void picture1();
void picture2();
void picture3(int i);
void picture4(int i);
