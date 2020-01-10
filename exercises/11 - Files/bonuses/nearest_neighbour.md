# Nearest Neighbour

Given a file containg information about iris flowers, predict the species of flower based on the most similar one in the dataset.

## Structure iris.csv

- Every line contains info about a flower, separated by commas
- First number is an ID, you can ignore it
- 2nd to 4th number are various sizes of a flower (sepal length, sepal width, petal length, petal width)
- Finally we have the species of the flower (string with at most 15 characters)

## Load Data

```c++
size_t load_data(const char * name, double examples[][dimensions + 1])
```

Given the name of a csv file (see Iris.csv), load the data into the exampes array and return the number of read examples

### Notes

- You will have to somehow encode the type of flower to a number to keep it in the array
- Assume no more than 1000 examples
- Assume no mistakes in the file format
- Only keep the 4 relevant dimensions and the encoded label

## Predict

```c++
const char * predict(double examples[][dimensions + 1], size_t size, double new_flower[dimensions + 1])
```

Given an array of examples, its size and an array containing the sizes of a new flower, predict the type of flower based on its nearest neighbour from the examples.

### Notes

- You will have to turn the predicted number to the correct label
- Treat all examples and the new flower as points in a 5D plane
- Find the nearest neighbour by eucledean distance

## Example

```c++
int main()
{
    double examples[max_size][dimensions + 1]{};
    size_t size{load_data("iris.csv", examples)};

    std::cout << size << '\n'; // 150

    double new_flower[dimensions + 1]{6.1, 3.3, 5.3, 2.4}; // Last element is unknown

    std::cout << predict(examples, size, new_flower) << '\n'; // Iris-virginica, closest to flower #149

    return 0;
}
```
