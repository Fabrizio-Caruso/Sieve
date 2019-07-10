unsigned int babylonian(unsigned int n)
{
    unsigned int x,y;
    
    x = n;
    y = 1;
    while(x>y)
    {
        x = (x+y)>>1;
        y = n/x;
    }
    return x;
}
