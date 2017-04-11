#include <iostream>
#include <vector>



class MatrixClass
{
public:
    std::vector< std::vector<int> >createMatrix();
    int rows;
    int columns;
};
    // allows user to create a matrix
std::vector< std::vector<int> > MatrixClass::createMatrix()
{
    std::vector< std::vector<int> >matrix;
    int num;

    std::cout << "Number of rows: " << std::endl;
    std::cin >> rows;
    std::cout << "Number of columns: " << std::endl;
    std::cin >> columns;

    std::cout << "Fill the matrix:" << std::endl;
    for(int i = 0; i < rows; i++)
    {
        matrix.resize(rows);
        for(int j = 0; j < columns; j++)
        {
            matrix[i].resize(columns);
            std::cin >> num;
            matrix[i][j] = num;
        }
        std::cout << std::endl;
    }

    return matrix;

}

// adds 2 matrices
std::vector< std::vector<int> > matrixAdder(std::vector< std::vector<int> > matrixA , std::vector< std::vector<int> > matrixB )
{
    std::vector< std::vector<int> > result;
    result.resize(matrixA.size());

    for(unsigned i = 0; i < matrixA.size(); i++)
    {
        result[i].resize(matrixA[i].size());
        for(unsigned j = 0; j < matrixB.size(); j++)
        {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    return result;
}

// prints a matrix
void matrixPrinter(const std::vector< std::vector<int> >& matrix)
{
    for(unsigned i = 0; i < matrix.size() ; i++)
    {
        std::cout << '|';
        for(unsigned j = 0; j < matrix[i].size() ; j++)
        {
            std::cout << ' ' << matrix[i][j] << ' ';
        }
        std::cout << '|';
        std::cout << std::endl;
    }
}

int main()
{
    MatrixClass matrA;
    MatrixClass matrB;

    std::vector< std::vector<int> >matr1 = matrA.createMatrix();
    std::vector< std::vector<int> >matr2 = matrB.createMatrix();



    if (matrA.columns == matrB.columns && matrA.rows == matrB.rows)
        matrixPrinter(matrixAdder(matr1, matr1));
    else
        std::cout << "Can't sum matrices of different dimensions";



}
