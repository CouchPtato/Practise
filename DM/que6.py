# Ground truth counts
actual_apples = 1000
actual_pears = 800

# Model predictions
correct_apples = 900
correct_pears = 700

# Confusion matrix values
TP = correct_apples          # True Positives: Apple predicted as Apple
FN = actual_apples - TP      # False Negatives: Apple predicted as Pear

TN = correct_pears           # True Negatives: Pear predicted as Pear
FP = actual_pears - TN       # False Positives: Pear predicted as Apple

# Display confusion matrix
print("Confusion Matrix:")
print(f"            Predicted Apple  Predicted Pear")
print(f"Actual Apple       {TP}              {FN}")
print(f"Actual Pear        {FP}              {TN}")

# Compute metrics
total = TP + TN + FP + FN
accuracy = (TP + TN) / total
error = 1 - accuracy
sensitivity = TP / (TP + FN)
precision = TP / (TP + FP)
f1 = 2 * (precision * sensitivity) / (precision + sensitivity)

print(f"\nAccuracy: {accuracy:.4f}")
print(f"Error Rate: {error:.4f}")
print(f"Sensitivity (Recall): {sensitivity:.4f}")
print(f"Precision: {precision:.4f}")
print(f"F1 Score: {f1:.4f}")
