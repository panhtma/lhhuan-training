# 1. Base Image: Start with a lightweight version of Linux that already has Python installed.
FROM python:3.9-slim

# 2. Working Directory: Create a folder inside the container to hold your code.
WORKDIR /app

# 3. Copy Files: Copy everything from your local project folder (.) into the container's /app folder (.).
COPY . .

# 5. Execution Command: Define the default command to run when the container starts.
CMD ["python", "app.py"]