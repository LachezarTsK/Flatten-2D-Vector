
public class Vector2D {

    int row;
    int column;
    int[][] vector;

    public Vector2D(int[][] vector) {
        this.vector = vector;
    }

    public int next() {
        if (!hasNext()) {
            throw new IndexOutOfBoundsException("row = " + row + " is out of bounds!");
        }
        return vector[row][column++];
    }

    public boolean hasNext() {
        moveForward();
        return row < vector.length;
    }

    public void moveForward() {
        while (row < vector.length && column == vector[row].length) {
            column = 0;
            row++;
        }
    }
}
