//
//  main.cpp
//  Sqrt
//
//  Created by Vinod Gupta on 2/3/15.
//  Copyright (c) 2015 vinodg. All rights reserved.
//

#include <iostream>

int getSqrtInt(int num)
{
    if(num <0)
        return 0;
    else if(num == 1)
        return 1;
    
    for(int i=1;i<(1+(num/2));++i)
    {
        int possible = i*i;
        if(possible==num)
            return i;
        else if(possible>num)
            return i-1;
    }
    return num;
}

int getSqrtIntBinSearch(int num)
{
    if(num <0)
        return 0;
    else if(num == 1)
        return 1;
    
    int low = 1;
    int high = 1+(num/2);
    while(low+1<high)
    {
        int mid = (low+high)/2;
        int square = mid*mid;
        if(square==num)
            return mid;
        else if(square>num)
        {
            low = mid;
        }else{
            high= mid;
        }
    }
    
    return num;
}

double getSqrtAprox1(int num)
{
    int floor =getSqrtIntBinSearch(num);//getSqrtInt(num);
    
    if(floor*floor==num)
        return floor;
    
    int ciel = floor + 1;
    
    double sloap = (ciel*ciel) - (floor*floor);
    return ((num-(ciel*ciel))/sloap) + ciel;
}

double getSqrtAprox2(int num)
{
    double sqrt = getSqrtAprox1(num);
    
    if(sqrt*sqrt==num)
        return sqrt;
    
    for(int i=1;i<100;++i)
    {
        double aprox = i*0.01;
        double target = sqrt+aprox;
        if((target*target) >= num)
            return target;
    }
    return sqrt;
}

int main(int argc, const char * argv[]) {
    
    std::cout<<"Num\tSqrt\n";
    for(int i=99980;i<99999;++i)
    {
        std::cout<<i<<"\t"<<getSqrtAprox2(i)<<"\n";
    }
    return 0;
}
