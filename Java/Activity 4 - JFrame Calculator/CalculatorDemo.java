import javax.swing.*;
import javax.swing.text.AbstractDocument;
import javax.swing.text.AttributeSet;
import javax.swing.text.BadLocationException;
import javax.swing.text.DocumentFilter;
import java.awt.*;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.Objects;

public class CalculatorDemo extends JFrame {

    // Calculation
    String currentNumberString = "";
    String newNumberString = "";
    String operation;

    // Buttons
    int buttonXIndex = 10;
    int buttonYIndex = 120;
    int buttonWidth = 65;
    int buttonHeight = 50;

    // Colors
    Color colorOperationBG = Color.decode("#3aa2a2");
    Color colorNumberBG = Color.decode("#70708e");

    // Font Configurations
    String primaryFont = "Castelar";
    String secondaryFont = "Tahoma";
    Font archiaFont;

    /**
     * Launch the application.
     */

    public static void main(String[] args) {
        startCalculator();
    }
    String formatNumber(Double number) {
        return new DecimalFormat("#.##").format(number);
    }

    static void startCalculator() {
        EventQueue.invokeLater(() -> {
            try {
                CalculatorDemo frame = new CalculatorDemo();
                frame.setVisible(true);
            } catch (Exception e) {
                e.printStackTrace();
            }
        });
    }

    /**
     * Create the frame.
     */

    public CalculatorDemo() {
        // Load Fonts
        archiaFont = null;
        try {
            archiaFont = Font.createFont(Font.TRUETYPE_FONT, Objects.requireNonNull(getClass().getResourceAsStream("Archia-Regular.otf"))).deriveFont(12f);
        } catch (IOException | FontFormatException exception) {
            exception.printStackTrace();
        }

        // Setup Frame
        setTitle("Calculator");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setBounds(100, 100, 300, 430);
        setResizable(false);
        JPanel contentPane = new JPanel();
        contentPane.setBackground(Color.decode("#15151c"));
        contentPane.setBorder(null);
        setContentPane(contentPane);
        contentPane.setLayout(null);

        // Setup Text Display
        JTextField textDisplay = new JTextField();
        textDisplay.setFont(archiaFont.deriveFont(30f));
        textDisplay.setForeground(Color.white);
        textDisplay.setBackground(Color.decode("#303040"));
        textDisplay.setBorder(null);
        textDisplay.setBounds(10, 30, 270, 80);
        contentPane.add(textDisplay);
        textDisplay.setColumns(10);

        {
            ((AbstractDocument) textDisplay.getDocument()).setDocumentFilter(new DocumentFilter() {
                @Override
                public void insertString(FilterBypass fb, int offset, String text, AttributeSet attr) throws BadLocationException {
                    String newText = null;
                    try {
                        newText = fb.getDocument().getText(0, fb.getDocument().getLength()) + text;
                    } catch (BadLocationException e) {
                        throw new RuntimeException(e);
                    }

                    if (newText.matches("^-?[0-9]*\\.?[0-9]*$")) {
                        super.insertString(fb, offset, text, attr);
                    }
                }

                @Override
                public void replace(FilterBypass fb, int offset, int length, String text, AttributeSet attrs) throws BadLocationException {
                    String newText = fb.getDocument().getText(0, fb.getDocument().getLength()).substring(0, offset) + text + fb.getDocument().getText(offset + length, fb.getDocument().getLength() - offset - length);

                    if (newText.matches("^-?[0-9]*\\.?[0-9]*$")) {
                        super.replace(fb, offset, length, text, attrs);
                    }
                }
            });
        }

        // Calculator Label
        JLabel title = new JLabel("CALCULATOR");
        title.setForeground(new Color(255, 255, 255));
        Font labelFont = archiaFont.deriveFont(Font.BOLD, 18f);
        title.setFont(labelFont);
        title.setHorizontalAlignment(SwingConstants.CENTER);
        title.setBounds(0, 5, 300, getHeight("CALCULATOR", labelFont));
        contentPane.add(title);
        
        // Clear Button
        JButton acButton = new JButton("AC");
        acButton.addActionListener(e -> textDisplay.setText(""));
        acButton.setFont(new Font(secondaryFont, Font.BOLD, 15));
        acButton.setForeground(Color.white);
        acButton.setBackground(Color.decode("#e5b900"));
        acButton.setBounds(getButtonBounds(0,0));
        acButton.setFocusPainted(false);
        acButton.setBorder(null);
        contentPane.add(acButton);

        // Backspace Button
        JButton backspaceButton = new JButton("\uF0D5");
        backspaceButton.addActionListener(e -> {
            String text = textDisplay.getText();
            if (!text.isEmpty()) {
                textDisplay.setText(text.substring(0, text.length() - 1));
            }
        });
        backspaceButton.setFont(new Font("Wingdings", Font.BOLD, 15));
        backspaceButton.setForeground(Color.white);
        backspaceButton.setBackground(Color.decode("#e5b900"));
        backspaceButton.setBounds(getButtonBounds(1,0));
        backspaceButton.setBorder(null);
        backspaceButton.setFocusPainted(false);
        contentPane.add(backspaceButton);

        // Number Buttons: 1, 2, 3, 4, 5, 6, 7, 8, 9 & 0
        Font numberFont = archiaFont.deriveFont(Font.BOLD, 20f);
        JButton oneButton = new JButton("1");
        oneButton.addActionListener(e -> textDisplay.setText(textDisplay.getText() + "1"));
        oneButton.setFont(numberFont);
        oneButton.setForeground(Color.white);
        oneButton.setBackground(colorNumberBG);
        oneButton.setBounds(getButtonBounds(0, 3));
        oneButton.setBorder(null);
        oneButton.setFocusPainted(false);
        contentPane.add(oneButton);

        JButton twoButton = new JButton("2");
        twoButton.addActionListener(e -> textDisplay.setText(textDisplay.getText() + "2"));
        twoButton.setFont(numberFont);
        twoButton.setForeground(Color.white);
        twoButton.setBackground(colorNumberBG);
        twoButton.setBounds(getButtonBounds(1,3));
        twoButton.setBorder(null);
        twoButton.setFocusPainted(false);
        contentPane.add(twoButton);

        JButton threeButton = new JButton("3");
        threeButton.addActionListener(e -> textDisplay.setText(textDisplay.getText() + "3"));
        threeButton.setFont(numberFont);
        threeButton.setForeground(Color.white);
        threeButton.setBackground(colorNumberBG);
        threeButton.setBounds(getButtonBounds(2,3));
        threeButton.setBorder(null);
        threeButton.setFocusPainted(false);
        contentPane.add(threeButton);

        JButton fourButton = new JButton("4");
        fourButton.addActionListener(e -> textDisplay.setText(textDisplay.getText() + "4"));
        fourButton.setFont(numberFont);
        fourButton.setForeground(Color.white);
        fourButton.setBackground(colorNumberBG);
        fourButton.setBounds(getButtonBounds(0,2));
        fourButton.setBorder(null);
        fourButton.setFocusPainted(false);
        contentPane.add(fourButton);

        JButton fiveButton = new JButton("5");
        fiveButton.addActionListener(e -> textDisplay.setText(textDisplay.getText() + "5"));
        fiveButton.setFont(numberFont);
        fiveButton.setForeground(Color.white);
        fiveButton.setBackground(colorNumberBG);
        fiveButton.setBounds(getButtonBounds(1,2));
        fiveButton.setBorder(null);
        fiveButton.setFocusPainted(false);
        contentPane.add(fiveButton);

        JButton sixButton = new JButton("6");
        sixButton.addActionListener(e -> textDisplay.setText(textDisplay.getText() + "6"));
        sixButton.setFont(numberFont);
        sixButton.setForeground(Color.white);
        sixButton.setBackground(colorNumberBG);
        sixButton.setBounds(getButtonBounds(2,2));
        sixButton.setBorder(null);
        sixButton.setFocusPainted(false);
        contentPane.add(sixButton);

        JButton sevenButton = new JButton("7");
        sevenButton.addActionListener(e -> textDisplay.setText(textDisplay.getText() + "7"));
        sevenButton.setFont(numberFont);
        sevenButton.setForeground(Color.white);
        sevenButton.setBackground(colorNumberBG);
        sevenButton.setBounds(getButtonBounds(0,1));
        sevenButton.setBorder(null);
        sevenButton.setFocusPainted(false);
        contentPane.add(sevenButton);

        JButton eightButton = new JButton("8");
        eightButton.addActionListener(e -> textDisplay.setText(textDisplay.getText() + "8"));
        eightButton.setFont(numberFont);
        eightButton.setForeground(Color.white);
        eightButton.setBackground(colorNumberBG);
        eightButton.setBounds(getButtonBounds(1,1));
        eightButton.setBorder(null);
        eightButton.setFocusPainted(false);
        contentPane.add(eightButton);

        JButton nineButton = new JButton("9");
        nineButton.addActionListener(e -> textDisplay.setText(textDisplay.getText() + "9"));
        nineButton.setFont(numberFont);
        nineButton.setForeground(Color.white);
        nineButton.setBackground(colorNumberBG);
        nineButton.setBounds(getButtonBounds(2,1));
        nineButton.setBorder(null);
        nineButton.setFocusPainted(false);
        contentPane.add(nineButton);

        JButton zeroButton = new JButton("0");
        zeroButton.addActionListener(e -> textDisplay.setText(textDisplay.getText() + "0"));
        zeroButton.setFont(numberFont);
        zeroButton.setForeground(Color.white);
        zeroButton.setBackground(colorNumberBG);
        zeroButton.setBounds(getButtonBounds(1,4));
        zeroButton.setBorder(null);
        zeroButton.setFocusPainted(false);
        contentPane.add(zeroButton);

        JButton decimalPoint = new JButton(".");
        decimalPoint.addActionListener(e -> textDisplay.setText(textDisplay.getText() + "."));
        decimalPoint.setFont(numberFont);
        decimalPoint.setForeground(Color.white);
        decimalPoint.setBackground(colorNumberBG);
        decimalPoint.setBounds(getButtonBounds(2,4));
        decimalPoint.setBorder(null);
        decimalPoint.setFocusPainted(false);
        contentPane.add(decimalPoint);

        // Operation Buttons
        Font operationFont = archiaFont.deriveFont(Font.BOLD, 20f);

        JButton divideButton = new JButton("/");
        divideButton.addActionListener(e -> {
            if (textDisplay.getText().isEmpty()) {
                return;
            }
            currentNumberString = textDisplay.getText();
            operation = "/";
            textDisplay.setText("");
        });
        divideButton.setFont(operationFont);
        divideButton.setForeground(Color.white);
        divideButton.setBackground(colorOperationBG);
        divideButton.setBounds(getButtonBounds(3,0));
        divideButton.setBorder(null);
        divideButton.setFocusPainted(false);
        contentPane.add(divideButton);

        JButton multiplyButton = new JButton("x");
        multiplyButton.addActionListener(e -> {
            if (textDisplay.getText().isEmpty()) {
                return;
            }
            currentNumberString = textDisplay.getText();
            operation = "*";
            textDisplay.setText("");
        });
        multiplyButton.setFont(operationFont);
        multiplyButton.setForeground(Color.white);
        multiplyButton.setBackground(colorOperationBG);
        multiplyButton.setBounds(getButtonBounds(3,1));
        multiplyButton.setBorder(null);
        multiplyButton.setFocusPainted(false);
        contentPane.add(multiplyButton);

        JButton subtractButton = new JButton("-");
        subtractButton.addActionListener(e -> {
            if (textDisplay.getText().isEmpty()) {
                return;
            }
            currentNumberString = textDisplay.getText();
            operation = "-";
            textDisplay.setText("");
        });
        subtractButton.setFont(operationFont);
        subtractButton.setForeground(Color.white);
        subtractButton.setBackground(colorOperationBG);
        subtractButton.setBounds(getButtonBounds(3,2));
        subtractButton.setBorder(null);
        subtractButton.setFocusPainted(false);
        contentPane.add(subtractButton);

        JButton addButton = new JButton("+");
        addButton.addActionListener(e -> {
            if (textDisplay.getText().isEmpty()) {
                return;
            }
            currentNumberString = textDisplay.getText();
            operation = "+";
            textDisplay.setText("");
        });
        addButton.setFont(operationFont);
        addButton.setForeground(Color.white);
        addButton.setBackground(colorOperationBG);
        addButton.setBounds(getButtonBounds(3, 3));
        addButton.setBorder(null);
        addButton.setFocusPainted(false);
        contentPane.add(addButton);

        JButton modularButton = new JButton("%");
        modularButton.addActionListener(e -> {
            if (textDisplay.getText().isEmpty()) {
                return;
            }
            currentNumberString = textDisplay.getText();
            operation = "%";
            textDisplay.setText("");
        });
        modularButton.setFont(operationFont);
        modularButton.setForeground(Color.white);
        modularButton.setBackground(colorOperationBG);
        modularButton.setBounds(getButtonBounds(2,0));
        modularButton.setBorder(null);
        modularButton.setFocusPainted(false);
        contentPane.add(modularButton);

        JButton toggleNegativeButton = new JButton("+/-");
        toggleNegativeButton.addActionListener(e -> {
            if (textDisplay.getText().isEmpty()) {
                return;
            }
            String text = textDisplay.getText();
            if (text.startsWith("-")) {
                textDisplay.setText(text.substring(1,text.length()));
                return;
            }
            System.out.println("");
            textDisplay.setText("-" + text);
        });
        toggleNegativeButton.setFont(operationFont);
        toggleNegativeButton.setForeground(Color.white);
        toggleNegativeButton.setBackground(colorOperationBG);
        toggleNegativeButton.setBounds(getButtonBounds(0,4));
        toggleNegativeButton.setBorder(null);
        toggleNegativeButton.setFocusPainted(false);
        contentPane.add(toggleNegativeButton);

        JButton equalButton = new JButton("=");
        equalButton.addActionListener(e -> {
            double answer = 0;

            newNumberString = textDisplay.getText();

            if (currentNumberString.isEmpty() || newNumberString.isEmpty()) {
                return;
            }

            double currentNumber = Double.parseDouble(currentNumberString);
            double newNumber = Double.parseDouble(newNumberString);

            switch (operation) {
                case "+" -> answer = currentNumber + newNumber;
                case "-" -> answer = currentNumber - newNumber;
                case "/" -> answer = currentNumber / newNumber;
                case "*" -> answer = currentNumber * newNumber;
                case "%" -> answer = currentNumber % newNumber;
            }

            textDisplay.setText(formatNumber(answer));
        });
        equalButton.setFont(operationFont);
        equalButton.setForeground(Color.white);
        equalButton.setBackground(Color.decode("#189a1c"));
        equalButton.setBounds(getButtonBounds(3,4));
        equalButton.setBorder(null);
        equalButton.setFocusPainted(false);
        contentPane.add(equalButton);
    }

    // Metrics
    public int getWidth(String text, Font font) {
        Graphics graphics = new java.awt.image.BufferedImage(1, 1, java.awt.image.BufferedImage.TYPE_INT_RGB).getGraphics();
        FontMetrics metrics = graphics.getFontMetrics(font);
        return metrics.stringWidth(text);
    }

    public int getHeight(String text, Font font) {
        Graphics graphics = new java.awt.image.BufferedImage(1, 1, java.awt.image.BufferedImage.TYPE_INT_RGB).getGraphics();
        FontMetrics metrics = graphics.getFontMetrics(font);
        return metrics.getHeight();
    }

    public Rectangle getButtonBounds(int x, int y) {
        return new Rectangle(buttonXIndex+(3+buttonWidth)*x, buttonYIndex+(3+buttonHeight)*y, buttonWidth, buttonHeight);
    }
}
