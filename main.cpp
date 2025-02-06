#include <iostream>
#include <string>

void primeFac(int j);

int main(){
    std::cout << "Enter a number " << std::endl;
    int num;
    std::cin >> num;

    primeFac(num);
}

void primeFac(int j){

    //int numbs[j];
    std::vector<int> nums;

    bool prime;

    int count = 0;
    for(int i = 2; i <= j; i++){
        prime = true;
        for(int k = 2; k < i; k++){
            if(i % k == 0){
                prime = false;
                break;
            }
        }

        if(prime){
            //std::cout << i << std::endl;
            //count++;
            nums.push_back(i);
            /*
            numbs[count] = i;
            count++;
            */
        }
    }

    //test to see if the variables are present
    for(int i: nums){
        std::cout << i << ' ';
    }

    std::cout << std::endl;

    //std::cout << "This is the size " << nums.size() << std::endl;

    
    std::string numbPri;
    int newValue, l;
    for(int i = 1; i <= nums.size() - 1; ++i){
        l = nums.at(nums.size()-(i+1));
        if(j % l == 0){
            //bool valid = true;
            
            do{
            newValue = j / l;
            numbPri += std::to_string(l) + " ";
            j = newValue;
            }
            while(j % l == 0);
            /*
            while(valid){
                newValue = j / l;
                
            }
            */
            //newValue = j / i;
            
            /*
            if(newValue == 1){
                numbPri += std::to_string(l) + " ";
            }
            
            j = newValue;
            numbPri += std::to_string(l) + " ";
            */
        }
        
    }

    if(numbPri.empty()){
        std::cout << "There are no prime factors " << std::endl;
    }
    else{
        std::cout << "This is the answer " << numbPri << std::endl;
    }
    
    


    /*
    for(int i = 0; i < sizeof(numbs) / sizeof(numbs[0]); i++){
        std::cout << numbs[i] << std::endl;
    }
    */
    
}