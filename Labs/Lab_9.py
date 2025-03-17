from PIL import Image, ImageEnhance

# Step 1: Open the image file
image = Image.open("cannon.png")  # Replace with your image file
image.show()  # Display the image to verify it's loaded correctly

# Step 2: Create a list to store frames
frames = []
enhancer = ImageEnhance.Brightness(image)

# Step 3: Generate frames with increasing brightness
for i in range(10):  # 10 frames
    factor = 1 + i * 0.2  # Gradually increase brightness
    new_frame = enhancer.enhance(factor)
    frames.append(new_frame)

# Step 4: Save frames as a GIF
frames[0].save(
    "cannon_brightening.gif",
    save_all=True,
    append_images=frames[1:],
    duration=100,  # 100 ms per frame
    loop=0  # Loop forever
)

print("GIF saved as cannon_brightening.gif")
