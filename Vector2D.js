
/**
 * @param {number[][]} vector
 */
var Vector2D = function (vector) {

    this.row = 0;
    this.column = 0;
    this.vector = vector;
};

/**
 * @return {number}
 */
Vector2D.prototype.next = function () {
    if (!this.hasNext()) {
        throw `row =  ${this.row} is out of bounds!`;
    }
    return this.vector[this.row][this.column++];
};

/**
 * @return {boolean}
 */
Vector2D.prototype.hasNext = function () {
    this.moveForward();
    return this.row < this.vector.length;
};

Vector2D.prototype.moveForward = function () {
    while (this.row < this.vector.length && this.column === this.vector[this.row].length) {
        this.column = 0;
        this.row++;
    }
};
