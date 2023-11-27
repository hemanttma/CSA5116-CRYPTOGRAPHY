def encrypt(text, shift):
    result = ""
    for char in text:
        if char.isalpha():
            # Determine if the character is uppercase or lowercase
            is_upper = char.isupper()
            
            # Shift the character by the specified amount
            char_code = ord(char)
            shifted_code = (char_code - ord('A' if is_upper else 'a') + shift) % 26
            encrypted_char = chr(shifted_code + ord('A' if is_upper else 'a'))
            
            result += encrypted_char
        else:
            # If the character is not an alphabet letter, leave it unchanged
            result += char

    return result

def decrypt(text, shift):
    # Decryption is essentially encryption with a negative shift
    return encrypt(text, -shift)

# Example usage:
plaintext = "Hello, World!"
shift_amount = 3

# Encrypt the plaintext
encrypted_text = encrypt(plaintext, shift_amount)
print("Encrypted:", encrypted_text)

# Decrypt the encrypted text
decrypted_text = decrypt(encrypted_text, shift_amount)
print("Decrypted:", decrypted_text)
