#!/usr/bin/env node
import fs = require('fs');

const lines: string[] = fs.readFileSync('./input.txt').toString().split('\n');

const trees: number[][] = [];
const visibleTrees: number[][] = [];

const viewDistanceUp: number[][] = [];
const viewDistanceRight: number[][] = [];
const viewDistanceDown: number[][] = [];
const viewDistanceLeft: number[][] = [];

let totalRows = 0;
let totalCols = 0;

GenerateData();

// Part 1
RowVisibility();
ColVisibility();
ResultPartOne();

// Part 2
CalculateViewDistances();
ResultPartTwo();

function GenerateData() {
    for (let row = 0; row < lines.length; row++) {
        const newRow: number[] = [];
        const newVisibleRow: number[] = [];

        for (let col = 0; col < lines[row].length; col++) {
            if (!Number.isNaN(Number.parseInt(lines[row][col]))) {
                newRow.push(Number.parseInt(lines[row][col]));
                newVisibleRow.push(1);
            }
        }
        trees.push(newRow);
        visibleTrees.push(newVisibleRow);
    }

    totalRows = trees.length;
    totalCols = trees[0].length;

    for (let row = 1; row < totalRows - 1; row++) {
        for (let col = 1; col < totalCols - 1; col++) {
            if (!Number.isNaN(Number.parseInt(lines[row][col]))) {
                visibleTrees[row][col] = 0;
            }
        }
    }
}

function RowVisibility() {
    for (let row = 0; row < totalRows; row++) {
        let maxHeightLeftToRight = trees[row][0];
        let maxHeightRightToLeft = trees[row][trees[row].length - 1];

        for (let col = 0; col < totalCols; col++) {
            if (trees[row][col] > maxHeightLeftToRight) {
                maxHeightLeftToRight = trees[row][col];
                visibleTrees[row][col] = 1;
            }
        }

        for (let col = totalCols - 1; col > 0; col--) {
            if (trees[row][col] > maxHeightRightToLeft) {
                maxHeightRightToLeft = trees[row][col];
                visibleTrees[row][col] = 1;
            }
        }
    }
}

function ColVisibility() {
    for (let col = 0; col < totalCols; col++) {
        let maxHeightTopToBottom = trees[0][col];
        let maxHeightBottomToTop = trees[totalRows - 1][col];

        for (let row = 0; row < totalRows; row++) {
            if (trees[row][col] > maxHeightTopToBottom) {
                maxHeightTopToBottom = trees[row][col];
                visibleTrees[row][col] = 1;
            }
        }
        
        for (let row = totalRows - 1; row > 0; row--) {
            if (trees[row][col] > maxHeightBottomToTop) {
                maxHeightBottomToTop = trees[row][col];
                visibleTrees[row][col] = 1;
            }
        }
    }
}

function ResultPartOne() {
    let totalVisibleTrees = 0;

    for (let row = 0; row < totalRows; row++) {
        for (let col = 0; col < totalCols; col++) {
            if (visibleTrees[row][col] > 0) {
                totalVisibleTrees++;
            }
        }
    }

    console.log(`Total visible trees: ${totalVisibleTrees}`);
}

function CalculateViewDistances() {
    for (let row = 0; row < totalRows - 1; row++) {
        const upRow: number[] = [];
        const rightRow: number[] = [];
        const downRow: number[] = [];
        const leftRow: number[] = [];

        for (let col = 0; col < totalCols - 1; col++) {
            upRow.push(CalculateDirectionViewDistance('up', row, col));
            rightRow.push(CalculateDirectionViewDistance('right', row, col));
            downRow.push(CalculateDirectionViewDistance('down', row, col));
            leftRow.push(CalculateDirectionViewDistance('left', row, col));
        }

        viewDistanceUp.push(upRow);
        viewDistanceRight.push(rightRow);
        viewDistanceDown.push(downRow);
        viewDistanceLeft.push(leftRow);
    }

    return;
}

function CalculateDirectionViewDistance(
    direction: 'up' | 'right' | 'down' | 'left',
    rowInput: number,
    colInput: number
): number {
    const targetTreeHeight = trees[rowInput][colInput];
    let viewDistance = 0;

    switch (direction) {
        case 'up':
            if (rowInput === 0) {
                break;
            }
            for (let row = rowInput - 1; row >= 0; row--) {
                viewDistance++;
                if (trees[row][colInput] >= targetTreeHeight) {
                    break;
                }
            }
            break;

        case 'right':
            if (colInput === totalCols) {
                break;
            }
            for (let col = colInput + 1; col < totalCols; col++) {
                viewDistance++;
                if (trees[rowInput][col] >= targetTreeHeight) {
                    break;
                }
            }
            break;

        case 'down':
            if (rowInput === totalRows) {
                break;
            }
            for (let row = rowInput + 1; row < totalRows; row++) {
                viewDistance++;
                if (trees[row][colInput] >= targetTreeHeight) {
                    break;
                }
            }
            break;

        case 'left':
            if (colInput === 0) {
                break;
            }
            for (let col = colInput - 1; col >= 0; col--) {
                viewDistance++;
                if (trees[rowInput][col] >= targetTreeHeight) {
                    break;
                }
            }
            break;
    }

    return viewDistance;
}

function CalculateScenicScore(rowInput: number, colInput: number): number {
    const up = viewDistanceUp[rowInput][colInput];
    const right = viewDistanceRight[rowInput][colInput];
    const down = viewDistanceDown[rowInput][colInput];
    const left = viewDistanceLeft[rowInput][colInput];

    return up * right * down * left;
}

function ResultPartTwo() {
    let highestScore = 0;
    for (let row = 0; row < totalRows - 1; row++) {
        for (let col = 0; col < totalCols - 1; col++) {
            const score = CalculateScenicScore(row, col);
            if (score > highestScore) {
                highestScore = score;
            }
        }
    }
    console.log(`Highest score: ${highestScore}`);
}
