#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<bits/stdc++.h>
using namespace std;
struct node{
    int a;
    struct node *left;
    struct node *right;
    struct node *next;
};
struct node *root;
struct node *last;
vector<vector<int>>v;
void insert(int t);
void inorder(struct node *temp);
void traversal(struct node *temp,vector<int>num);
int main(){
  vector<int>num;
    insert(10);
    insert(30);
    insert(15);
    insert(40);
    insert(20);
    insert(50);
    inorder(root);
    traversal(root,num);
    for(int i=0;i<v.size();i++){
      for(int j=0;j<v[i].size();j++){
        cout<<v[i][j]<<" ";
      }
      cout<<endl;
    }
    return 0;
}

void insert(int t){
    struct node *temp,*p1,*par;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->a=t;
    temp->next=last;
    last=temp;
    temp->left=NULL;
    temp->right=NULL;
    p1=root;
    par=NULL;
    while(p1!=NULL){
        par=p1;
        if(t<p1->a){
            p1=p1->left;
        }
        else{
            p1=p1->right;
        }
    }
    if(par==NULL){
        root==temp;
    }
    else{
    if(t<par->a){
        par->left=temp;
    }
    else{
        par->right=temp;
    }
    }
}
void inorder(struct node *temp){

    if(temp==NULL){
        return ;
    }
    else{
        inorder(temp->left);
        printf("->%d",temp->a);
        inorder(temp->right);
    }
}

void traversal(struct node *temp,vector<int>num){
  if(temp==NULL){
    return ;
  }
  num.push_back(temp->a);
  if(temp->right==NULL && temp->left==NULL){
    v.push_back(num);
  }
  traversal(temp->left,num);
  traversal(temp->right,num);
}
