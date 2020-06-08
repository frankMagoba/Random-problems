import java.io.*;
import java.util.*;

public class BotClean {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int m = 5;

        String[] posInput = in.nextLine().split(" ");

        int x = Integer.parseInt(posInput[0]);
        int y = Integer.parseInt(posInput[1]);

        char grid[][] = new char[m][m];

        for (int i = 0; i < m; i++) {
            grid[i] = in.next().toCharArray();
        }

      System.out.println((new BotClean()).next_move(x, y, grid));
        in.close();

    }
    private class Coords implements Comparable<Coords> {
        int x, y;
        Integer moves;
        Coords next;

        public Coords(int xTarget, int yTarget) {
            x = xTarget;
            y = yTarget;
            //            moves = Math.abs(xSource - xTarget) + Math.abs(ySource - yTarget) + 1;
        }

        public int calculateMoves(Coords target) {
            return Math.abs(target.x - x) + Math.abs(target.y - y) + 1;
        }

        @Override
        public String toString() {
            return "{" + this.x + "," + this.y + ":" + this.moves + "-> " + next + "}";
        }

        @Override
        public int compareTo(Coords o) {
            return this.moves.compareTo(o.moves);
        }

    }

    private Coords buildPath(ArrayList<Coords> al, int xSource, int ySource) {
        int path = 999;
        Coords next = null, current = new Coords(xSource, ySource);

        if (!al.isEmpty()) {
            for (int i = 0; i < al.size(); i++) {
                Coords tmp = al.remove(i);
                Coords coords = buildPath(al, tmp.x, tmp.y);
                int tmpMoves = coords.calculateMoves(current);
                if (path > tmpMoves) {
                    path = tmpMoves;
                    next = coords;
                }
                al.add(i, coords);

            }
            current.next = next;
            current.moves = path;
        } else {
            current.moves = 1;
        }

        return current;
    }

    public String next_move(int xBot, int yBot, char[][] grid) {
        int xTarget = 0, yTarget = 0;
        String output = "";
        ArrayList<Coords> al = new ArrayList<Coords>();

        for (int i = 0; i < grid.length; i++) {
            char[] row = grid[i];
            for (int j = 0; j < row.length; j++) {
                if (row[j] == 'd') {
                    al.add(new Coords(i, j));
                }
            }
        }

        Coords start = new Coords(xBot, yBot);
        if (!al.contains(new Coords(xBot, yBot))) {
            start = buildPath(al, xBot, yBot).next;
        }

        if (start != null) {
            xTarget = start.x;
            yTarget = start.y;
        }

        if ((xTarget - xBot) > 0) {
            output = ("DOWN");
        } else if ((xTarget - xBot) < 0) {
            output = ("UP");
        } else if ((yTarget - yBot) < 0) {
            output = ("LEFT");
        } else if ((yTarget - yBot) > 0) {
            output = ("RIGHT");
        } else if (xTarget == xBot && yTarget == yBot) {
            output = ("CLEAN");
        }
        return output;
    }

}
