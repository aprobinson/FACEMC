Shielding analysis of a 300cm x 300cm x 30 cm slab of iron concrete
c
c
c -----------------------------------------------------------------------------c
c Cell block-------------------------------------------------------------------c
c -----------------------------------------------------------------------------c
c
c Cell 10 is the volume of iron portland concrete that is doing the shielding
10  1  -5.90  100 -101 102 -103 104 -105    IMP:n=1
c Cell 20 is a void
20  0  200 -201 202 -203 204 -205 #10       IMP:n=1
c Cell 30 is the graveyard 
30  0  #20 #10                              IMP:n=0
c
c
c ----------------------------------------------------------------------------c
c MCNP necessary space--------------------------------------------------------c
c ----------------------------------------------------------------------------c

c ----------------------------------------------------------------------------c
c Surface block---------------------------------------------------------------c
c ----------------------------------------------------------------------------c
c
c the 100 series define the inner cube made of iron portland concrete
c
100 PX -15
101 PX 15
102 PY -150
103 PY 150
104 PZ -150
105 PZ 150
c 
c the 200 series define the middle cube filling a void
c 
200 PX -25
201 PX 25
202 PY -160
203 PY 160
204 PZ -160
205 PZ 160
c
c
c
c ----------------------------------------------------------------------------c
c MCNP necessary space--------------------------------------------------------c
c ----------------------------------------------------------------------------c

c ----------------------------------------------------------------------------c
c Data block------------------------------------------------------------------c
c ----------------------------------------------------------------------------c
c
c
c Material Definition
c
m1    1001.80c  0.135585
      8016.80c  0.150644
     12024.80c  0.0017496285  12025.80c  0.0002215  12026.80c  0.0002438715
     13027.80c  0.005065
     14028.80c  0.0123754214  14029.80c  0.0006266206  14030.80c  0.000415958
     16032.80c  0.0006138292  16033.80c  0.000004845  16034.80c  2.71966E-05
     20040.80c  0.0396672878  20042.80c  0.0002647459  20043.80c  5.524065E-05
     20044.80c  0.0008535703  20048.80c  7.651853E-05
     25055.80c  0.002638
     26054.80c  0.037634402  26056.80c  0.5951454128  26057.80c  0.014275118
     26058.80c  0.0018168332
c
c
c --------------------
c Source
c --------------------
c monodirectional, monoenergetic 2.45 MeV point source located
c just before the the edge of the shield
SDEF  ERG=2.45 POS=-20 0 0 DIR=1 VEC=1 0 0 
c --------------------
c Job Control
c --------------------
c run in neutron only mode
mode n
c run for 100 histories
nps 1000000000
c Surface current on front surface
f11:n 100
c11  0.99 1
c
c Surface current on back surface
f21:n 101
c21  0.99 1
c
c Track length flux tally
c FMESH4:n  ORIGIN=-15 -150 -150
c          EMESH=1e-6 99ilog 2.45    EINTS=0 98 7r 
c          IMESH=30          IINTS=1
c          JMESH=300         JINTS=1
c          KMESH=300         KINTS=1
F4:n  10
E4 1e-6 98ilog 2.45
