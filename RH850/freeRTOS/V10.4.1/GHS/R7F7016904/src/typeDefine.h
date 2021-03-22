#ifndef TYP_IODEF_TYPEDEF_
#define TYP_IODEF_TYPEDEF_

/*typedef unsigned char   uint8;
typedef unsigned short  uint16;
typedef unsigned long   uint32;
*/
#define protected_write_test(preg,pstatus,reg,value)   do{\
                                                  (preg)=0xa5u;\
                                                  (reg)=(value);\
                                                  (reg)=~(value);\
                                                  (reg)=(value);\
                                                  }while((pstatus)==1u)

#endif
