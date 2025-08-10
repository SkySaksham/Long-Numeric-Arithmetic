// BENCHMARK: 10k! -- Java implementation
// This code calculates the factorial of 10,000 using BigInteger to handle large numbers.

import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;

public class Java_10k {

    // Calculate factorial using BigInteger
    public static BigInteger factorial(int n) {
        BigInteger result = BigInteger.ONE;
        for (int i = 2; i <= n; i++) {
            result = result.multiply(BigInteger.valueOf(i));
        }
        return result;
    }

    public static void main(String[] args) {
        // Pre-Requisite Data
        // Total Digits: 35660
        // First 10 Digits: 2846259680

        final int totalDigits = 35660;
        final String firstTenDigits = "2846259680";

        // WARM UP RUNS (3 runs)
        for (int w = 0; w < 3; w++) {
            factorial(10000);
        }

        // Allow GC and pause to reduce interference
        System.gc();
        try {
            Thread.sleep(100);
        } catch (InterruptedException ignored) {}

        // Verify correctness after warm-up
        BigInteger warmUpResult = factorial(10000);
        String warmUpStr = warmUpResult.toString();

        if (warmUpStr.length() != totalDigits || !warmUpStr.startsWith(firstTenDigits)) {
            System.out.println("Warm-up run failed: Incorrect number of digits or first ten digits.");
            return;
        }

        System.out.println("Warm-up run successful: " + warmUpStr.length() + " digits.");
        System.out.println("First 10 digits: " + warmUpStr.substring(0, 10));

        // TIMED RUNS
        final int runs = 5;
        List<Long> durations = new ArrayList<>();

        for (int i = 0; i < runs; i++) {
            System.out.println("\nRun " + (i + 1) + ":");

            long start = System.nanoTime();
            BigInteger result = factorial(10000);
            long end = System.nanoTime();

            long duration = (end - start) / 1_000_000; // convert to milliseconds
            durations.add(duration);

            System.out.println("Time taken: " + duration + " milliseconds");
            System.out.println("Total digits: " + result.toString().length());
        }

        // Calculate average
        double average = durations.stream().mapToLong(Long::longValue).average().orElse(0.0);

        // Calculate standard deviation
        double variance = 0.0;
        for (long d : durations) {
            variance += (d - average) * (d - average);
        }
        variance /= runs;
        double stddev = Math.sqrt(variance);

        System.out.println("\nAverage time: " + average + " milliseconds");
        System.out.println("Standard deviation: " + stddev + " milliseconds");
    }
}
