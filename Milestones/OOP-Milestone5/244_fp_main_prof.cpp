#include "PosApp.h"
int main(){
  ict::PosApp app("244_fp_data.txt", "244_fp_bill.txt");
  app.run();
  return 0;
}
