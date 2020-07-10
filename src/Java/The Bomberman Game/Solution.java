import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static String[][] getResults(String[][] startingGrid, String[][] o_grid, int seconds, int rows, int columns,
            boolean longLoop) {
        String[][] currentGrid = new String[rows][columns];
        currentGrid = o_grid;
        if (seconds == 1) {
            return startingGrid;
        }
        if (seconds % 2 == 0) {
            return o_grid;
        }
        String[][] new_O_grid_one = new String[rows][columns];
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < columns; c++) {
                new_O_grid_one[r][c] = "O";
                if (startingGrid[r][c].equals("O")) {
                    currentGrid[r][c] = ".";

                    if (r - 1 >= 0) {
                        currentGrid[r - 1][c] = ".";
                    }
                    if (r + 1 < rows) {
                        currentGrid[r + 1][c] = ".";
                    }
                    if (c - 1 >= 0) {
                        currentGrid[r][c - 1] = ".";
                    }
                    if (c + 1 < columns) {
                        currentGrid[r][c + 1] = ".";
                    }
                }
            }
        }
        startingGrid = currentGrid;
        currentGrid = new_O_grid_one;
        if (seconds == 3) {
            return startingGrid;
        }
        String[][] new_O_grid_two = new String[rows][columns];
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < columns; c++) {
                new_O_grid_two[r][c] = "O";
                if (startingGrid[r][c].equals("O")) {
                    currentGrid[r][c] = ".";

                    if (r - 1 >= 0) {
                        currentGrid[r - 1][c] = ".";
                    }
                    if (r + 1 < rows) {
                        currentGrid[r + 1][c] = ".";
                    }
                    if (c - 1 >= 0) {
                        currentGrid[r][c - 1] = ".";
                    }
                    if (c + 1 < columns) {
                        currentGrid[r][c + 1] = ".";
                    }
                }
            }
        }
        startingGrid = currentGrid;
        currentGrid = new_O_grid_two;
        if (((seconds - 3) / 2) % 2 != 0) {
            return startingGrid;
        }
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < columns; c++) {

                if (startingGrid[r][c].equals("O")) {
                    currentGrid[r][c] = ".";

                    if (r - 1 >= 0) {
                        currentGrid[r - 1][c] = ".";
                    }
                    if (r + 1 < rows) {
                        currentGrid[r + 1][c] = ".";
                    }
                    if (c - 1 >= 0) {
                        currentGrid[r][c - 1] = ".";
                    }
                    if (c + 1 < columns) {
                        currentGrid[r][c + 1] = ".";
                    }
                }
            }
        }
        startingGrid = currentGrid;

        return startingGrid;
    }

    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);

        int rows = reader.nextInt();
        int columns = reader.nextInt();
        int seconds = reader.nextInt();
        String[][] startingGrid = new String[rows][columns];
        String[][] o_grid = new String[rows][columns];
        boolean longLoop = false;
        for (int i = 0; i < rows; i++) {
            String input = reader.next();
            if (input.contains("O.O")) {
                longLoop = true;
            }
            for (int j = 0; j < columns; j++) {
                startingGrid[i][j] = Character.toString(input.charAt(j));
                o_grid[i][j] = "O";
            }
        }

        String[][] results = getResults(startingGrid, o_grid, seconds, rows, columns, longLoop);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                System.out.print(results[i][j]);

            }
            System.out.println();
        }
    }
}