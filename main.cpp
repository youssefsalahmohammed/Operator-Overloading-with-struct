// Course:  CS213 - Programming II  - 2018
// Title:   Assignment I - Task 1 - Problem 1
// Program: CS213-2018-A1-T1-P1
// Purpose: Skeleton code for the student to start working
// Author:  youssef salah mohammed - youssef maher danial - ali ahmed ahmed gad
// G : 13
// ID : 20170344
// Date:    10 August 2018
// Version: 1.0

#include <iostream>
#include <iomanip>
//#include <cassert>

using namespace std;
int sum=0;
// A structure to store a matrix
struct matrix
{
    int** data;       // Pointer to 2-D array that will simulate matrix
    int row, col;
};

// Already implemented
void createMatrix (int row, int col, int num[], matrix& mat);

// Student #1 with the smallest ID (e.g., 20170080)
// All these operations return a new matrix with the calculation result
matrix operator+  (matrix mat1, matrix mat2); // Add if same dimensions
matrix operator-  (matrix mat1, matrix mat2); // Sub if same dimensions
matrix operator*  (matrix mat1, matrix mat2); // Multi if col1 == row2
matrix operator+  (matrix mat1, int scalar);  // Add a scalar
matrix operator-  (matrix mat1, int scalar);  // Subtract a scalar
matrix operator*  (matrix mat1, int scalar);  // Multiple by scalar

// Student #2 with the middle ID (e.g., 20170082)
// The last operator >> takes an istream and a matrix and return the
// the same istream so it is possible to cascade input like
// cin >> matrix1 >> matrix2 << endl;
matrix operator+= (matrix& mat1, matrix mat2); // mat1 changes & return
// new matrix with the sum
matrix operator-= (matrix& mat1, matrix mat2); // mat1 changes + return new
// matrix with difference
matrix operator+= (matrix& mat, int scalar);   // change mat & return new matrix
matrix operator-= (matrix& mat, int scalar);   // change mat & return new matrix
void   operator++ (matrix& mat);   	// Add 1 to each element ++mat
void   operator-- (matrix& mat);    	// Sub 1 from each element --mat
istream& operator>> (istream& in, matrix& mat);
// Input matrix like this (dim 2 x 3) cin >> 2 3 4 6 8 9 12 123
// and return istream to allow cascading input

//Student #3 with the biggest ID (e.g., 20170089)
ostream& operator<< (ostream& out, matrix mat);
// Print matrix  as follows (2 x 3)			4	 6 	  8
// and return ostream to cascade printing	9	12  	123
bool   operator== (matrix mat1, matrix mat2);	// True if identical
bool   operator!= (matrix mat1, matrix mat2); 	// True if not same
bool   isSquare   (matrix mat);  // True if square matrix
bool   isSymetric (matrix mat1,matrix mat2); // True if square and symmetric
bool   isIdentity (matrix mat);  // True if square and identity
matrix transpose(matrix mat);    // Return new matrix with the transpose




//__________________________________________

int main()
{

    int data1 [] = {1,2,3,4,5,6,7,8};
    int data2 [] = {13,233,3,4,5,6};
    int data3 [] = {10,100,10,100,10,100,10,100};

    matrix mat1, mat2, mat3,mat;
    createMatrix (4, 2, data1, mat1);  // the function which will create the matrix
    createMatrix (2, 3, data2, mat2);  // the function which will create the matrix
    createMatrix (4, 2, data3, mat3);  // the function which will create the matrix




    cout<<"matrix no.1 : \n"<<mat1<<endl;
    cout<<endl<<endl;
    cout<<"matrix no.2 : \n"<<mat2<<endl;
    cout<<endl<<endl;
    cout<<"matrix no.3 : \n"<<mat3<<endl;
    cout<<endl<<endl;



//_________________________________________



    mat=mat1+mat3;
    cout<<"mat1 + mat3 = \n";
    for(int i=0; i<mat1.row; i++) // cout << (mat1);
    {
        for(int j=0; j<mat1.col; j++)
        {
            cout<<mat.data[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;


    mat=mat1-mat3;
    cout<<"mat1 - mat3 = \n";
    for(int i=0; i<mat1.row; i++) // cout << (mat1);
    {
        for(int j=0; j<mat1.col; j++)
        {
            cout<<mat.data[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;


    mat=mat1*mat3;
    cout<<"mat1 * mat3 = \n";
    for(int i=0; i<mat1.row; i++) // cout << (mat1);
    {
        for(int j=0; j<mat1.col; j++)
        {
            cout<<mat.data[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;






//_________________________________________



    cout<<"mat1 + 5 =  \n"<<mat1+5<<endl;
    cout<<endl<<endl;
    cout<<"mat1 - 5 =  \n"<<mat1-5<<endl;
    cout<<endl<<endl;
    cout<<"mat1 * 5 =  \n"<<mat1*5<<endl;
    cout<<endl<<endl;
//_________________________________________


    mat1+=mat3;
    cout<<"mat1+=mat3 : \n"<<mat1<<endl;
    cout<<endl<<endl;
    mat1-=mat3;
    cout<<"mat1-=mat3 : \n"<<mat1<<endl;
    cout<<endl<<endl;


    mat1+= mat3 += mat3;
    cout <<"mat1 after this operation (mat1+= mat3 += mat3) is equal : \n"<< mat1 << endl;
    cout<<endl<<endl;
    cout <<"mat3 after this operation (mat1+= mat3 += mat3) is equal : \n"<< mat3 << endl;
    cout<<endl<<endl;


//_________________________________________


    mat1+=15;
    cout<<"mat1+=15 : \n"<<mat1<<endl;
    cout<<endl<<endl;
    mat1-=15;
    cout<<"mat1-=15 : \n"<<mat1<<endl;
    cout<<endl<<endl;


//_________________________________________

    ++mat1;
    cout<<"mat1++ : \n"<<mat1<<endl;
    cout<<endl<<endl;

    ++mat2;
    cout<<"mat2++ : \n"<<mat2<<endl;
    cout<<endl<<endl;
    ++mat3;
    cout<<"mat3++ : \n"<<mat3<<endl;
    cout<<endl<<endl;

//_________________________________________

    --mat1;
    cout<<"mat2-- : \n"<<mat1<<endl;
    cout<<endl<<endl;
    --mat2;
    cout<<"mat2-- : \n"<<mat2<<endl;
    cout<<endl<<endl;
    --mat3;
    cout<<"mat2-- : \n"<<mat3<<endl;
    cout<<endl<<endl;


//_________________________________________

    cout<<"enter the matrix : "<<endl;
    cin>>mat1; // ifstream and ofstream
    cout<<"The matrix which you entered is : \n" <<mat1<<endl;
    cout<<endl<<endl;


//_________________________________________

    if(mat1==mat3) // True if identical (== operator)
        cout<<"they are identical"<<endl;
    else
        cout<<"they are not identical"<<endl;

    cout<<endl<<endl;

//_________________________________________

    if(mat1!=mat3)  // True if not same (!= operator)
        cout<<"they are identical"<<endl;
    else
        cout<<"they are not identical"<<endl;

    cout<<endl<<endl;
//_________________________________________

    // function will be square when the number of rows equal number of columns.

    cout<<isSquare(mat1)<<endl;  // square or not
    cout<<isSquare(mat2)<<endl;
    cout<<isSquare(mat3)<<endl;

    cout<<endl<<endl;


//_________________________________________

    // function will be Symmetric when the matrix equal its transpose
    // and number of rows equal number of columns.

    cout<<isSymetric(mat1,mat1)<<endl; // Symmetric or not
    cout<<isSymetric(mat2,mat2)<<endl;
    cout<<isSymetric(mat3,mat3)<<endl;

    cout<<endl<<endl;


//_________________________________________



    // function will be Identity when all number in it equal 0 except the number of the main diameter equal 1
    // and the matrix should be symmetric too.

    cout<<isIdentity(mat1)<<endl; // Identity or not
    cout<<isIdentity(mat2)<<endl;
    cout<<isIdentity(mat3)<<endl;

    cout<<endl<<endl;
//_________________________________________



    transpose(mat1); // transpose of the matrix 1
    transpose(mat2); // transpose of the matrix 2
    transpose(mat3); // transpose of the matrix 3

    cout<<endl<<endl;


}



// Takes an array of data and stores in matrix according
// to rows and columns
void createMatrix (int row, int col, int num[], matrix& mat) // the function which will create the matrix
{
    mat.row = row;
    mat.col = col;
    mat.data = new int* [row];

    for (int i = 0; i < row; i++)
        mat.data[i] = new int [col];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            mat.data[i][j] = num[i * col + j];
}


//_______________________________________________________________________________________________


matrix operator+  (matrix mat1, matrix mat2) // sum two object (we can use / or * or - instead of +)
{
    if(mat1.col==mat2.col && mat1.row==mat1.row)
    {
        matrix result;
        result.data=new int* [mat1.row];

        for (int i = 0; i < mat1.row; i++)
            result.data[i] = new int [mat1.col];

        for(int i=0; i<mat1.row; i++)
        {
            for(int j=0; j<mat1.col; j++)
            {
                result.data[i][j]=mat1.data[i][j]+mat2.data[i][j];
            }
        }
        return result;
    }
}

//_______________________________________________________________________________________________


matrix operator-  (matrix mat1, matrix mat2) // sum two object (we can use / or * or - instead of +)
{
    if(mat1.col==mat2.col && mat1.row==mat1.row)
    {
        matrix result;
        result.data=new int* [mat1.row];

        for (int i = 0; i < mat1.row; i++)
            result.data[i] = new int [mat1.col];

        for(int i=0; i<mat1.row; i++)
        {
            for(int j=0; j<mat1.col; j++)
            {
                result.data[i][j]=mat1.data[i][j]-mat2.data[i][j];
            }
        }
        return result;
    }
}
//_______________________________________________________________________________________________


matrix operator*  (matrix mat1, matrix mat2) // sum two object (we can use / or * or - instead of +)
{
    if(mat1.col==mat2.col && mat1.row==mat2.row)
    {
        matrix result;
        result.data=new int* [mat1.row];

        for (int i = 0; i < mat1.row; i++)
            result.data[i] = new int [mat1.col];

        for(int i=0; i<mat1.row; i++)
        {
            for(int j=0; j<mat1.col; j++)
            {
                result.data[i][j]=mat1.data[i][j]*mat2.data[i][j];
            }
        }
        return result;
    }
}

//_______________________________________________________________________________________________

matrix operator+  (matrix mat1, int scalar) // sum object to integer (we can use / or * or - instead of +)
{
    for(int i=0; i<mat1.row; i++)
    {
        for(int j=0 ; j<mat1.col ; j++)
        {
            mat1.data[i][j]=mat1.data[i][j]+scalar;
        }
    }
    return mat1;
}

//_______________________________________________________________________________________________

matrix operator-  (matrix mat1, int scalar) // sum object to integer (we can use / or * or - instead of +)
{
    for(int i=0; i<mat1.row; i++)
    {
        for(int j=0 ; j<mat1.col ; j++)
        {
            mat1.data[i][j]=mat1.data[i][j]-scalar;
        }
    }
    return mat1;
}

//_______________________________________________________________________________________________

matrix operator*  (matrix mat1, int scalar) // sum object to integer (we can use / or * or - instead of +)
{
    for(int i=0; i<mat1.row; i++)
    {
        for(int j=0 ; j<mat1.col ; j++)
        {
            mat1.data[i][j]=mat1.data[i][j]*scalar;
        }
    }
    return mat1;
}

//_______________________________________________________________________________________________

matrix operator+= (matrix& mat1, matrix mat2) // sum two object (we can use /= or *= or -= instead of +=)
{
    if(mat1.col==mat2.col && mat1.row==mat2.row)
    {
        for(int i=0; i<mat1.row; i++)
        {
            for( int j=0 ; j<mat1.col; j++ )
            {
                mat1.data[i][j]+=mat2.data[i][j];
            }
        }

    }

}

//_______________________________________________________________________________________________


matrix operator-= (matrix& mat1, matrix mat2) // sum two object (we can use /= or *= or -= instead of +=)
{
    if(mat1.col==mat2.col && mat1.row==mat2.row)
    {
        for(int i=0; i<mat1.row; i++)
        {
            for( int j=0 ; j<mat1.col; j++ )
            {
                mat1.data[i][j]-=mat2.data[i][j];
            }
        }

    }

}

//_______________________________________________________________________________________________


matrix operator+= (matrix& mat1, int scalar) // sum  object to integer (we can use /= or *= or -= instead of +=)
{
    for(int i=0; i<mat1.row; i++)
    {
        for(int j=0; j<mat1.col; j++)
        {
            mat1.data[i][j]+=scalar;
        }
    }
}

//_______________________________________________________________________________________________

matrix operator-= (matrix& mat1, int scalar) // sum  object to integer (we can use /= or *= or -= instead of +=)
{
    for(int i=0; i<mat1.row; i++)
    {
        for(int j=0; j<mat1.col; j++)
        {
            mat1.data[i][j]-=scalar;
        }
    }
}


//_______________________________________________________________________________________________

void   operator++ (matrix& mat1) // increase each element of the array by 1 (we can use -- instead of ++)
{
    for(int i=0; i<mat1.row; i++)
    {
        for(int j=0 ; j<mat1.col ; j++)
        {
            mat1.data[i][j]++;
        }
    }

}

//_______________________________________________________________________________________________


void   operator-- (matrix& mat1) // increase each element of the array by 1 (we can use -- instead of ++)
{
    for(int i=0; i<mat1.row; i++)
    {
        for(int j=0 ; j<mat1.col ; j++)
        {
            mat1.data[i][j]--;
        }
    }

}

//_______________________________________________________________________________________________


istream& operator>> (istream& in, matrix& mat) // make cin for the object
{
    for(int i=0; i<mat.row; i++)
    {
        for(int j=0 ; j<mat.col ; j++)
        {
            in>>mat.data[i][j];
        }
    }
    return in;

}

//_______________________________________________________________________________________________

ostream& operator<< (ostream& out, matrix mat) //make cout for the object
{
    for(int i=0; i<mat.row; i++)
    {
        for(int j=0 ; j<mat.col ; j++)
        {
            out<<mat.data[i][j]<<" ";
        }
        cout<<endl;
    }
    return out;

}

//_______________________________________________________________________________________________


bool   operator== (matrix mat1, matrix mat2) // check if matrix 1 equal matrix 2 or not (we can use int instead of bool)
{
    for(int i=0; i<mat1.row; i++)
    {
        for(int j=0; j<mat1.col; j++)
        {
            if(mat1.data[i]==mat2.data[i])
                sum++;
        }

    }
    if(sum==mat1.col*mat1.row)
        return true;
    else
        return false;
}


//_______________________________________________________________________________________________



bool   operator!= (matrix mat1, matrix mat2) // check if matrix 1 equal matrix 2 or not (we can use int instead of bool)
{
    int sum0=0;
    for(int i=0; i<mat1.row; i++)
    {
        for(int j=0; j<mat1.col; j++)
        {
            if(mat1.data[i]==mat2.data[i])
                sum0++;
        }

    }
    if(sum0!=mat1.col*mat1.row)
        return true;
    else
        return false;
}

//_______________________________________________________________________________________________



bool   isSquare   (matrix mat) // check if the matrix is square or not  (we can use int instead of bool)
{
    return (mat.row==mat.col? true : false);
}

//_______________________________________________________________________________________________


bool   isSymetric (matrix mat1,matrix mat)  // check if the matrix is symetric or not  (we can use int instead of bool)
{
    int sum2=0;
    if(mat1.row==mat1.col)
    {

        for(int i=0; i<mat1.row; i++)
        {
            for(int j=0; j<mat1.col; j++)
            {
                mat1.data[j][i]=mat.data[i][j];
            }
        }
        for(int i=0; i<mat1.row; i++)
        {
            for(int j=0; j<mat1.col; j++)
            {
                if(mat1.data[i][j]==mat.data[i][j])
                    sum2++;
            }
        }
        if(sum2==mat1.row*mat1.col)
            return true;
        else
            return false;
    }
    else
        return false;


}

//_______________________________________________________________________________________________


bool   isIdentity (matrix mat) // check if the matrix is identity or not  (we can use int instead of bool)
{
    int k=0;
    int sum1=0;
    if(mat.row==mat.col)
    {
        for(int i=0; i<mat.row; i++)
        {
            for(int j=0; j<mat.col; j++)
            {
                if(mat.data[i][j]==0)
                    sum1++;
                if(k==j && mat.data[i][j]==1)
                    sum1++;
            }
            k++;
        }


        if(sum1==mat.col*mat.row)
            return true;
        else
            return false;
    }
    else
        return false;

}


//_______________________________________________________________________________________________

matrix transpose(matrix mat) // make transpose for the matrix
{
    cout<<"The transpose of the matrix : \n";
    for(int i=0; i<mat.col; i++)
    {
        for(int j=0; j<mat.row; j++)
        {
            cout<<mat.data[j][i]<<" ";
        }
        cout<<endl;
    }
}
