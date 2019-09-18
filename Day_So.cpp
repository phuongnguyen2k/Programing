#include <ostream>
#include <fstream>
using namespace std;
long long a[300001],g[300001],f[300001];
int main(){
    ifstream infile("seq.txt");
    ofstream outfile("Outseq.txt");
    unsigned long n;
    long long max=0;
    //doc du lieu tu file vao mang a va tinh mang g
    infile>>n;
    infile>>a[1]>>a[2]>>a[3];
    max=a[1]+a[2]+a[3] ;
    f[3]=max;
    for(int i=4;i<=n;i++){
        infile>>a[i];        
        g[1]=a[i];
        printf("\ni=%d",i);
        for(int l=2;l<=i;l++)
        {
            g[l]=g[l-1]+a[i-l+1];
			printf("\ng[%d]=%d---------%d----%d",l,g[l],a[i-l+1],i-l+1);    //tinh s[n]
            if((l%3==0)&&(max<g[l])) {
			max=g[l];printf("\n\t-->l:%d",l);
			} //chi xet nhung doan co co do dai chia het cho 3
        }
        printf("\n");
        f[i]=(f[i-1]>max)?f[i-1]:max;        
    }
    outfile<<max;
    infile.close();
    outfile.close();    
    return 0;
}
