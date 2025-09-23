package Calculator;

import javafx.event.ActionEvent;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.layout.VBox;

public class Controller {

    public TextField calcScreen;
    public VBox rootVBox;
    public Button clearButton;
    public Button multButton;
    public Button minButton;
    public Button equalButton;
    public Button divButton;
    public Button posButton;
    public Button plusButton;

    private String n1 = "";
    private String n2 = "";
    private String lastN2 = "";
    private boolean firstNumber = true;
    private String operator = "";
    private String lastOperator = "";
    private double lastResult = 0;

    public void clearAction(ActionEvent event) {
        if (firstNumber) {
            if (n1.equals("")) {
                calcScreen.setText("");
                operator = "";
                firstNumber = true;
                n1 = "";
                n2 = "";
                updateScreen();
            } else {
                n1 = "";
            }
        } else {
            if (n2.equals("")) {
                calcScreen.setText("");
                operator = "";
                firstNumber = true;
                n1 = "";
                n2 = "";
                updateScreen();
            } else {
                n2 = "";
            }
        }

        updateScreen();
    }

    public void equalAction(ActionEvent event) {
        solve();
    }

    public void posAction(ActionEvent event) {
        if (firstNumber) {

            if (n1.contains("-")) {
                n1 = n1.substring(1);
            } else {
                n1 = "-" + n1;
            }

        } else {

            if (n2.contains("-")) {
                n2 = n2.substring(1);
            } else {
                n2 = "-" + n2;
            }

        }
        updateScreen();
    }

    public void decAction(ActionEvent event) {
        if (firstNumber) {
            if (!n1.contains("."))
                n1 += ".";
        } else {
            if (!n2.contains("."))
                n2 += ".";
        }
        updateScreen();
    }

    public void plusAction(ActionEvent event) {
        operator = "+";
        firstNumber = false;
        updateScreen();
    }

    public void minAction(ActionEvent event) {
        operator = "-";
        firstNumber = false;
        updateScreen();
    }

    public void multAction(ActionEvent event) {
        operator = "*";
        firstNumber = false;
        updateScreen();
    }

    public void divAction(ActionEvent event) {
        operator = "/";
        firstNumber = false;
        updateScreen();
    }

    public void zeroAction(ActionEvent event) {
        if (firstNumber)
            n1 += "0";
        else
            n2 += "0";
        updateScreen();
    }

    public void oneAction(ActionEvent event) {
        if (firstNumber)
            n1 += "1";
        else
            n2 += "1";
        updateScreen();
    }

    public void twoAction(ActionEvent event) {
        if (firstNumber)
            n1 += "2";
        else
            n2 += "2";
        updateScreen();
    }

    public void threeAction(ActionEvent event) {
        if (firstNumber)
            n1 += "3";
        else
            n2 += "3";
        updateScreen();
    }

    public void fourAction(ActionEvent event) {
        if (firstNumber)
            n1 += "4";
        else
            n2 += "4";
        updateScreen();
    }

    public void fiveAction(ActionEvent event) {
        if (firstNumber)
            n1 += "5";
        else
            n2 += "5";
        updateScreen();
    }

    public void sixAction(ActionEvent event) {
        if (firstNumber)
            n1 += "6";
        else
            n2 += "6";
        updateScreen();
    }

    public void sevenAction(ActionEvent event) {
        if (firstNumber)
            n1 += "7";
        else
            n2 += "7";
        updateScreen();
    }

    public void eightAction(ActionEvent event) {
        if (firstNumber)
            n1 += "8";
        else
            n2 += "8";
        updateScreen();
    }

    public void nineAction(ActionEvent event) {
        if (firstNumber)
            n1 += "9";
        else
            n2 += "9";
        updateScreen();
    }

    private void updateScreen(){
        if (firstNumber){
            calcScreen.setText(n1);
        } else {
            calcScreen.setText(operator + " " + n2);
        }
    }

    private void updateScreen(String s) {
        calcScreen.setText(s);
    }


    private void solve() {
        if (n2.equals(""))
            n2 = lastN2;
        if (!n2.equals("") && !n1.equals("")) {
            if (operator.equals(""))
                operator = lastOperator;

            double num1 = Double.parseDouble(n1);
            double num2 = Double.parseDouble(n2);

            switch (operator) {
                case "+":
                    lastResult = num1 + num2;
                    updateScreen(String.valueOf(lastResult));
                    break;
                case "-":
                    lastResult = num1 - num2;
                    updateScreen(String.valueOf(lastResult));
                    break;
                case "*":
                    lastResult = num1 * num2;
                    updateScreen(String.valueOf(lastResult));
                    break;
                case "/":
                    lastResult = num1 / num2;
                    updateScreen(String.valueOf(lastResult));
                    break;
            }

            lastN2 = n2;
            lastOperator = operator;

            n1 = String.valueOf(lastResult);
            n2 = "";
            firstNumber = false;
        }
    }
}
