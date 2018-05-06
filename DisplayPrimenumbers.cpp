/* Enter your code here. Read input from STDIN. Print output to STDOUT */
void displayPrimeNumbers(int val1, int val2) {
    int count =0, i;
        
        for(i =val1;i<=val2;i++)
        {
            for(int j =2; j<=sqrt(i); j++)
            {
             if(i % j ==0)
             {
                count++;
             }
            }
            if(count ==0 && i !=1)
            {
              cout<< i <<endl;
              count =0;
            }
            count =0;
        }
        
}
