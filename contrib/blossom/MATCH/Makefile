# Change these parameters how you want them to be
     CON_PATH = ${HOME}/src/concorde97
           CC = gcc -m32
       CFLAGS =  -g 

# From here nothing needs to be changed
      INCDIRS =  -I$(CON_PATH)

           LD = $(CC)

         LIBS = -lm 

      BLOSSOM = mat_main.c match.c matprice.c 
        PRICE = mp_main.c matprice.c 
     TRI_CALL = tri_call.c           

  BLOSSOMOBJS = $(BLOSSOM:.c=.o)
    PRICEOBJS = $(PRICE:.c=.o)
 TRI_CALLOBJS = $(TRI_CALL:.c=.o)

all    : blossom4 price4 tri_call

blossom4 : $(BLOSSOMOBJS)
	$(LD) -o $@  $(BLOSSOMOBJS) $(CON_PATH)/libconcorde.a -lm 
price4 : $(PRICEOBJS)
	$(LD) -o $@  $(PRICEOBJS) $(CON_PATH)/libconcorde.a -lm
tri_call : $(TRI_CALLOBJS)
	$(LD) -o $@  $(TRI_CALLOBJS) -lm

install : all

clean  :
	rm -f *.o blossom4 price4 tri_call

depend :
	makedepend $(INCDIRS) $(SEQU)

.c.o :
	$(CC) $(CFLAGS) $(INCDIRS) -c $*.c


