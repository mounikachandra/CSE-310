/* Recitation-2 mile stone
* 
* Author : Mounika Gandavarapu
* Version: 10-16-2018
*
*/
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <bits/stdc++.h>
#include <cmath>
#include "stdio.h"
#include "defn.h"

using namespace std;
int flagPrice = 1;
int flagRangePrice = 1;
int flagRangeApp = 1;
int flagCat = 1;

tree *newNode(app_info info) 
{ 
    tree *temp = new tree; 
    temp->info  = info; 
    temp->left  =  NULL;
    temp->right = NULL;
    return (temp); 
}

bool TestForPrime( int val )
{
    int limit, factor = 2;

    limit = (long)( sqrtf( (float) val ) + 0.5f );
    while( (factor <= limit) && (val % factor) )
        factor++;

    return( factor > limit );
}
string* splitString(string line) {
	string *arrayString = new string[20000];
	string *result = new string[20000];
	string delimiter = " ";
	int position = 0;
	int currPosition = 0;
	int k = 0;
	int previousPosition = 0;
	do{
		position = line.find(delimiter,currPosition);
		if(position>=0) {
			currPosition = position;
			arrayString[k]=line.substr(previousPosition,currPosition-previousPosition);
			currPosition++;
			previousPosition= currPosition;
			k++;
		}
	} while(position>=0);
	arrayString[k]= line.substr(previousPosition,line.length());
	int newValue = k+2;
	stringstream ss;
	ss<<newValue;
	result[0]=ss.str();
//	cout<<sizeof(arrayString)/sizeof(*arrayString)<<endl;
	for(int m=0;m<k+1;m++) {
		result[m+1] = arrayString[m];
	}
//	cout<<result[0];
	return result;
}
int countNodes(struct tree *root) { 
	if(root==NULL) {
		return 0;
	} 
    int left=countNodes(root->left);
    int right= countNodes(root->right); 
    return left+right+1;
}
char* strip(char *charArray) {
	int charArraylen = strlen(charArray);
	char *newCharArray = new char[charArraylen-1];
	for(int i = 0;i<charArraylen-1;i++)
	{
		newCharArray[i] = charArray[i];
	}
	return newCharArray;
}
int heightOfTree(struct tree *root) {
	if(root==NULL) {
		return 0;
	}
    int left = heightOfTree(root->left);
    int right = heightOfTree(root->right);
    return max(left,right)+1; 
}
void inorderTraversal(struct tree *root) { 
    if (root != NULL) 
    { 
        inorderTraversal(root->left);
        cout<<"Application Name: " << root->info.app_name << "Height of left subtree: " << heightOfTree(root->left) << "Count of left subtree: "<< countNodes(root->left) <<"Height of right tree: " << heightOfTree(root->right) << "Count of right subtree: " << countNodes(root->right) <<endl;
        inorderTraversal(root->right);
    } 
}
void inorderTraversalFree(struct tree *root) { 
    if (root != NULL) 
    { 
        inorderTraversalFree(root->left);
        if(root->info.price==0.00) {
        	flagPrice = 0;
        	cout<<root->info.app_name<<endl;
		}
        //cout<<"Application Name: " << root->info.app_name << "Height of left subtree: " << heightOfTree(root->left) << "Count of left subtree: "<< countNodes(root->left) <<"Height of right tree: " << heightOfTree(root->right) << "Count of right subtree: " << countNodes(root->right) <<endl;
        inorderTraversalFree(root->right);
    } 
}

void inorderRangePriceTraversal(struct tree *root,float low,float high) { 
    if (root != NULL) 
    { 
        inorderRangePriceTraversal(root->left,low,high);
        if(root->info.price >= low && root->info.price <= high) {
        	flagRangePrice = 0;
        	cout<<root->info.app_name<<endl;
		}
        //cout<<"Application Name: " << root->info.app_name << "Height of left subtree: " << heightOfTree(root->left) << "Count of left subtree: "<< countNodes(root->left) <<"Height of right tree: " << heightOfTree(root->right) << "Count of right subtree: " << countNodes(root->right) <<endl;
        inorderRangePriceTraversal(root->right,low,high);
    } 
}
void inorderRangeAppTraversal(struct tree *root,char *appLow,char *appHigh) { 
    if (root != NULL) 
    { 
        inorderRangeAppTraversal(root->left,appLow,appHigh);
        if(strcmp(root->info.app_name,appLow)>=0 && strcmp(root->info.app_name,appHigh)<=0 ) {
        	flagRangeApp = 0;
        	cout<<root->info.app_name<<endl;
		}
        //cout<<"Application Name: " << root->info.app_name << "Height of left subtree: " << heightOfTree(root->left) << "Count of left subtree: "<< countNodes(root->left) <<"Height of right tree: " << heightOfTree(root->right) << "Count of right subtree: " << countNodes(root->right) <<endl;
        inorderRangeAppTraversal(root->right,appLow,appHigh);
    } 
}
struct tree *newNode(string category, string appName) 
	{ 
    tree *temp =  new tree(); 
    strcpy(temp->info.category ,category.c_str());
    strcpy(temp->info.app_name,appName.c_str());
    string version;
	getline(cin,version);
//	cout<<"newnodeversion"<<endl;
//	cout<< version<<endl;
	strcpy(temp->info.version,version.c_str());
	string sizeString;
	getline(cin,sizeString);
	stringstream ssSize(sizeString);
	ssSize>>temp->info.size;
//	cout<<"ssSize"<<endl;
//	cout<< temp->info.size<<endl;
	string units;
	getline(cin,units);
//	cout<<"units"<<endl;
//	cout<< units<<endl;
	strcpy(temp->info.units,units.c_str());
	string priceString;
	getline(cin,priceString);
	stringstream ssPrice(priceString);
	ssPrice>>temp->info.price;
//	cout<<"price"<<endl;
//	cout<< temp->info.price<<endl;
    temp->left = NULL;
	temp->right = NULL; 
    return temp; 
	} 
struct tree* insertIntoBST(struct tree* node, string category,string appName) {
    if (node == NULL) {
    	return newNode(category,appName); 
	}
    if (appName < node->info.app_name) 
        node->left  = insertIntoBST(node->left, category, appName); 
    else if (appName > node->info.app_name) 
        node->right = insertIntoBST(node->right, category, appName);
    return node; 
}
void rangePrice(char *categoryName,float low,float high,categories *inputCategories,int noOfCategories) {
//	cout<<categoryName<<endl;
//	cout<<low<<endl;
//	cout<<high<<endl;
	for(int i = 0;i<noOfCategories;i++) {
//			cout<<categoryName<<endl;
//			cout<<inputCategories[i].category<<endl;
		if(strcmp(categoryName,strip(inputCategories[i].category))==0 || strcmp(strip(categoryName),strip(inputCategories[i].category))==0) {
//			cout<< "jkbkbk"<<categoryName<<endl;
//			cout<<"bhvbjhvjhv"<<inputCategories[i].category<<endl;
			inorderRangePriceTraversal(inputCategories[i].root,low,high);
		}
	}
	if(flagRangePrice==1) {
		cout<< "No Applications found for given range" <<endl;
	}
	flagRangePrice=1;
}

void rangeApp(char *categoryName,char* appLow,char* appHigh,categories *inputCategories,int noOfCategories) {
	for(int i = 0;i<noOfCategories;i++) {
		if(strcmp(categoryName,strip(inputCategories[i].category))==0) {
			inorderRangeAppTraversal(inputCategories[i].root,appLow,appHigh);
		}
	}
	if(flagRangeApp==1) {
		cout<< "No Applications found for given range" <<endl;
	}
	flagRangeApp=1;
}
void findCategory(char *categoryName,categories *inputCategories,int noOfCategories ) {
//	    cout<<categoryName<<endl;
//		cout<<noOfCategories<<endl;
	for(int i = 0; i<noOfCategories;i++) {
//		cout<<inputCategories[i].category<<endl;
//		cout<<"categoryName " << strlen(strip(categoryName))<<endl;
//		cout<<"inputcategoryName " << strlen(inputCategories[i].category)<<endl;
//		cout<<"changed" << strlen(strip(inputCategories[i].category))<<endl;
		
		if(strcmp(categoryName,strip(inputCategories[i].category))==0 || strcmp(strip(categoryName),strip(inputCategories[i].category))==0){ 
			cout<<categoryName<<endl;
			flagCat = 0;
			inorderTraversal(inputCategories[i].root);
		}
	}
	if(flagCat==1) {
		cout<< "Category not found" <<endl;
	}
	flagCat=0;
}
void findFree(categories *inputCategories,int noOfCategories ) {
//	    cout<<categoryName<<endl;
//		cout<<noOfCategories<<endl;
	for(int i = 0; i<noOfCategories;i++) {
		//	cout<< "khlkhlk" <<endl;
			inorderTraversalFree(inputCategories[i].root);
	}
	if(flagPrice==1) {
		cout<< "No free Application found" <<endl;
	}
	flagPrice==1;
}

int hashGeneration(char* name,int tableSize) {
	int count=0;
		for(int i=0;i<strlen(name);i++)
		{
			count=count+int(name[i]);
		}
		return count%tableSize;
}

void insertIntoHashTable(struct tree *root,int tableSize,struct hash_table_entry** hashTable) { 
	if (root != NULL) {
	    insertIntoHashTable(root->left,tableSize,hashTable); 
	    hash_table_entry* tempRoot= new hash_table_entry();
	    strcpy(tempRoot->app_name,root->info.app_name);
	    tempRoot->app_node=root;
	    int index=hashGeneration(root->info.app_name,tableSize);
	    tempRoot->next=hashTable[index];
	    hashTable[index]=tempRoot;
	    insertIntoHashTable(root->right,tableSize,hashTable);
	}
}
void printHashTable(struct hash_table_entry** hashTable,int tableSize) {
	cout << "HashTable with Number of Nodes of each set size: " <<endl; 
	int temp[tableSize];
	for (int i=0;i<tableSize;i++){
		temp[i]=0;
	}
	for (int i=0;i<tableSize;i++){
		//cout << "Inside lOOP: " <<endl; 
		hash_table_entry* reference=hashTable[i];
		int counter=0;
		while(reference!=NULL)
		{
			reference=reference->next;
			counter++;
		}
		temp[counter]++;
	}
	for (int i=0;i<tableSize;i++){
		if (temp[i]!=0)
		{
			cout<< i << setw(10) << temp[i] <<endl;
		}
			
	}
}

void printLoadFactor(int noOfApps, int tableSize){
	float loadFactor=float(noOfApps)/float(tableSize);
		cout << "loadFactor: " << loadFactor <<endl; 
		cout << "--------------"<< endl;
}



void delHashEntry(struct hash_table_entry *root,char* hashapp_name)
	{
		hash_table_entry *first=NULL;
		//hash_table_entry *second=root;
		while(root!=NULL)
		{
			if (!strcmp(root->app_name,hashapp_name))
			{
				first->next=root->next;
				return;
			}
			else
			{
				first=root;
				//second=root->next;
				root=root->next;
			}
		}

	}


struct tree * minValueNode(struct tree* node) 
	{ 
    struct tree* current = node; 
  
    /* loop down to find the leftmost leaf */
    while (current->left != NULL) 
        current = current->left; 
  
    return current; 
	}


struct tree* deleteBst(struct tree* root, char* key) 
	{ 
    // base case 
    if (root == NULL) return root; 
  
    // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 
    if (key < root->info.app_name) 
        root->left = deleteBst(root->left, key); 
  
    // If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
    else if (key > root->info.app_name) 
        root->right = deleteBst(root->right, key); 
  
    // if key is same as root's key, then This is the node 
    // to be deleted 
    else
    { 
        // node with only one child or no child 
        if (root->left == NULL) 
        { 
            struct tree *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct tree *temp = root->left; 
            free(root); 
            return temp; 
        } 
  
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        struct tree* temp = minValueNode(root->right); 
  
        // Copy the inorder successor's content to this node 
        strcpy(root->info.category,temp->info.category);
        strcpy(root->info.app_name,temp->info.app_name);
        strcpy(root->info.version,temp->info.version);
        root->info.size = temp->info.size;
        strcpy(root->info.units,temp->info.units);
        root->info.price = temp->info.price; 
  
        // Delete the inorder successor 
        root->right = deleteBst(root->right, temp->info.app_name); 
    } 
    return root; 
} 

void searchInHash(struct hash_table_entry *root,char* hashapp_name) 
	{ 
		if (root==NULL)
		{
			cout<<"Application not found."<<endl;
			return;
		}
	    if (!strcmp(root->app_name,hashapp_name)) 
	    { 
	    	cout<<root->app_node->info.category<<endl;cout<<root->app_node->info.app_name<<endl;cout<<root->app_node->info.version<<endl;cout<<root->app_node->info.size<<endl;cout<<root->app_node->info.units<<endl;cout<<root->app_node->info.price<<endl;
	    	return;
	    }
	    
	    searchInHash(root->next,hashapp_name);    
	}

int main()
{
	string  stringCategories;
	getline(cin,stringCategories);   
//	cout<<"stringCategories"<<endl;
//	cout<<stringCategories<<endl;
	int noOfCategories;
	stringstream ssCat(stringCategories);
	ssCat>>noOfCategories;
//	cout<<"noOfCategories"<<endl;
//	cout<<noOfCategories<<endl;
	
	categories *inputCategories = new categories[noOfCategories];
	
	int count = 0;
	for(int i = 0; i< noOfCategories;i++) {
		string tempCategories; 
		getline(cin,tempCategories);
		strcpy(inputCategories[i].category , tempCategories.c_str());	
	}
	string allApps;
	int countOfApps;
	getline(cin,allApps);
	//cout<<allApps<<endl;
	stringstream ssApps(allApps);
	ssApps>>countOfApps;
//	cout<<"countOfApps"<<endl;
  //  cout<<countOfApps<<endl;
    bool foundPrime = false;
    int startPrimeCounter = 2*countOfApps+1;
    while(!foundPrime) {
    	if( TestForPrime(startPrimeCounter) ) {
			foundPrime = true;
		} else {
			startPrimeCounter++;
		}
	}
    hash_table_entry** hashTable= new hash_table_entry*[startPrimeCounter];
    	for(int i=0;i<startPrimeCounter;i++){
			hashTable[i]=NULL;
		}
	string inputCat;
	int noOfApps = countOfApps;
	while(countOfApps>0) {
		getline(cin,inputCat);
		char consoleCat[25];
		strcpy(consoleCat,inputCat.c_str());
		string app;
		getline(cin,app);
//		cout<<"app"<<endl;
//    	cout<<app<<endl;
		for(int i = 0; i<noOfCategories;i++) {
//				cout<<"outside"<<endl;
//				cout<<inputCategories[i].category<<endl;
//				cout<<"check"<<endl;
//				cout<<consoleCat<<endl;
			if(!strcmp(consoleCat,inputCategories[i].category)){
//				cout<<"inside"<<endl;
//				cout<<consoleCat<<endl;
				inputCategories[i].root = insertIntoBST(inputCategories[i].root,inputCat,app);
				//inorderTraversal(inputCategories[i].root);
				break;
			}
		}
		countOfApps--;
	}
	for (int i=0;i<noOfCategories;i++){
		insertIntoHashTable(inputCategories[i].root,startPrimeCounter,hashTable);
		//cout<<hash_table[0]<<"hash_table"<<endl;
	}
	//	cout<<hashTable[0]<<"hash_table"<<endl;
	printHashTable(hashTable,startPrimeCounter);
	printLoadFactor(noOfApps,startPrimeCounter);
	
	string commands;
	int noOfCommands;
	getline(cin,commands);
	stringstream ssCommands(commands);
	ssCommands>>noOfCommands;
	//cout<<noOfCommands<<endl;
	char cat[25];
	string freeComm;
	char appName[25];
	float low;
	float high;
	char appLow[25];
	char appHigh[25];
	string delimiter = " ";
	string *splitArray = new string[2000];
	for(int i = 0; i<noOfCommands;i++) {
//		string comm;
//		getline(cin,comm);
//		string splitString;
//		string *output = new string[30];
//    	istringstream stringStream(comm);
//    	int a =0;
//    	while(getline(stringStream,splitString,'\n')) {
//    		stringstream ss(splitString);
//    		ss>>output[a];
//    		cout<<output[a];
//		}
		string firstCommand;
		getline(cin,firstCommand);
		splitArray= splitString(firstCommand);
		int len;
		string slen = splitArray[0];
		stringstream sslen(slen);
		sslen>>len;
		//cout<<len<<endl;
//		for(int l = 0; l<len;l++) {
//			cout<<splitArray[l]<<endl;
//		}
		if(splitArray[1]=="find"&&splitArray[2]=="category") {
			string newString = "";
			for(int p=3;p<len;p++) {
				newString.append(splitArray[p]);
				if(p!=len-1) {
					newString.append(" ");
				}
			}
//			cout<<"ojojlohoihjoi"<<endl;
//			cout<<newString<<endl;
			char charnewString[newString.size()];
			strcpy(charnewString,newString.c_str());
			findCategory(charnewString,inputCategories,noOfCategories);
			cout<<"*********************************"<<endl;
		} else if(splitArray[1]=="find"&&splitArray[2]=="price") {
			cout<<"find price free:"<<endl;
			findFree(inputCategories,noOfCategories);
			cout<<"*********************************"<<endl;
		} 
		else if(splitArray[1]=="find"&&splitArray[2]=="app") {
			string newString = "";
			for(int p=3;p<len;p++) {
				newString.append(splitArray[p]);
				if(p!=len-1) {
					newString.append(" ");
				}
			}
			char charnewString[newString.size()];
			strcpy(charnewString,newString.c_str());
			cout<<"find app:"<<endl;
			int index=hashGeneration(charnewString,startPrimeCounter);
			searchInHash(hashTable[index],charnewString);
			cout<<"*********************************"<<endl;
		}
		else if(splitArray[1]=="range" && splitArray[len-3]=="price" ) {
			string newStringRange = "";
			for(int p=2;p<len-3;p++) {
				newStringRange.append(splitArray[p]);
				if(p!=len-4) {
					newStringRange.append(" ");
				}
			}
			//cout<<newStringRange;
			float low;
			string lowSS = splitArray[len-2];
			stringstream sslow(lowSS);
			sslow>>low;
			float high;
			string highSS = splitArray[len-1];
			stringstream sshigh(highSS);
			sshigh>>high;
			char charnewStringRange[newStringRange.size()];
			strcpy(charnewStringRange,newStringRange.c_str());
			//cout<<newStringRange;
			rangePrice(charnewStringRange,low,high,inputCategories,noOfCategories);
			cout<<"*********************************"<<endl;
		} else if(splitArray[1]=="range" && splitArray[len-3]=="app" ) {
			string newStringApp = "";
			for(int p=2;p<len-3;p++) {
				newStringApp.append(splitArray[p]);
				if(p!=len-4) {
					newStringApp.append(" ");
				}
			}
			char charnewStringApp[newStringApp.size()];
			strcpy(charnewStringApp,newStringApp.c_str());
			//cout<<newStringApp;
			char charLowStringApp[splitArray[len-2].size()];
			strcpy(charLowStringApp,splitArray[len-2].c_str());
			//cout<<charLowStringApp;
			char charHighStringApp[splitArray[len-1].size()];
			strcpy(charHighStringApp,splitArray[len-1].c_str());
			//cout<<newStringApp;
			rangeApp(charnewStringApp,charLowStringApp,charHighStringApp,inputCategories,noOfCategories);
			cout<<"*********************************"<<endl;
        }
        else if(splitArray[1]=="delete"){
        	string cmd2= splitArray[2];char cmd2_1[50];strcpy(cmd2_1,cmd2.c_str());

					int q=3;
					int k = len;
					//int found=0;
					for (int j=0;j<k;j++)
					{
						int n=0;
						//cout<< "cmp" << strcmp(cmd2_1,array[n].category)!=0 <<endl;
						while(n< noOfCategories && strcmp(cmd2_1,inputCategories[n].category)!=0)
							{n++;}
						if (n!=noOfCategories)
						{
							break;
						}
						cmd2 += " ";
						cmd2 += splitArray[q];
						q++;
						strcpy(cmd2_1,cmd2.c_str());

					}
					cout<<"-----------------"<<cmd2_1<<endl;
					char cmd3_1[50];string cmd3;
					cout << q<<endl;
					cout << k << endl;
					while(q<k)
					{cmd3 += splitArray[q];cmd3 += " ";q++;}
					cmd3 += splitArray[k];
					strcpy(cmd3_1,cmd3.c_str());

					cout<<"-----------------"<<cmd3_1<<endl;
					int index=hashGeneration(cmd3_1,startPrimeCounter);
					//cout << ind << endl;

					if (hashTable[index]==NULL)
					{
						cout << "Application not found" << endl ;
					}

					else if (!strcmp(hashTable[index]->app_name,cmd3_1))
					{
						hashTable[index]=NULL;
						cout << "App deleted from hash_table"<<endl;
						//cout<<"::::::"<<endl;
					}
					else
					{
						delHashEntry(hashTable[index],cmd3_1);
						cout << "App deleted from hash_table"<<endl;
						//cout<<"::::::"<<endl;
						
					}
					
					for (int m=0;m< noOfCategories; m++)
					{
						//cout<<"::::::"<<endl;
						if (!strcmp(inputCategories[m].category,cmd2_1))
						{
							inputCategories[m].root=deleteBst(inputCategories[m].root,cmd3_1);
							cout << "App deleted from bst"<<endl;
						}
					}
					
		}
	}
}
