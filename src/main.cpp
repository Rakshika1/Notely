#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <stdio.h>
#include "todo.h"
#define GL_SILENCE_DEPRECATION
#include <GLFW/glfw3.h> // Will drag system OpenGL headers

static void glfw_error_callback(int error, const char* description) {
    fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

// Main code
int main(int, char**) {
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        return 1;

    // Decide GL+GLSL versions
    const char* glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    // Create window with graphics context
    GLFWwindow* window = glfwCreateWindow(800, 600, "To-Do App", nullptr, nullptr);
    if (window == nullptr)
        return 1;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    // Customizing ImGui style
    ImGui::StyleColorsDark();
    ImGuiStyle& style = ImGui::GetStyle();
    style.WindowRounding = 10.0f; // Round window corners
    style.FrameRounding = 5.0f; // Round frame corners
    style.ItemSpacing = ImVec2(10, 10); // Spacing between items

    // Customize colors
    style.Colors[ImGuiCol_WindowBg] = ImVec4(0.1f, 0.1f, 0.15f, 1.00f); // Dark background
    style.Colors[ImGuiCol_Text] = ImVec4(1.0f, 1.0f, 1.0f, 1.0f); // White text
    style.Colors[ImGuiCol_FrameBg] = ImVec4(0.2f, 0.2f, 0.25f, 1.0f); // Frame background
    style.Colors[ImGuiCol_Button] = ImVec4(0.3f, 0.5f, 0.8f, 1.00f); // Button color
    style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.4f, 0.6f, 1.0f, 1.00f); // Button hover color
    style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.2f, 0.4f, 0.6f, 1.00f); // Button active color

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Poll and handle events
        glfwPollEvents();

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Create the main window with the title "To-Do App"
        ImGui::SetWindowSize(ImVec2(800, 600));
        ImGui::Begin("To-Do App");

        // Section title
        ImGui::Text("My To-Do List");
        ImGui::Separator();

        // New Task Entry Section
        ImGui::Text("Add New Task:");
        ImGui::InputText("New Task", newTask, IM_ARRAYSIZE(newTask));
        ImGui::SameLine();
        if (ImGui::Button("Add Task")) {
            addTask(); // Add task without automatic checking
        }
        ImGui::Separator();

        // Task List Section
        ImGui::Text("Tasks:");
        ImGui::BeginChild("TaskList", ImVec2(0, 400), true);

        // Display tasks
        int taskNumber = 1; // For numbering tasks
        for (int i = 0; i < tasks.size(); i++) {
            bool isCompleted = (taskStatus[i] == 1); // Get completion status

            // Display only incomplete tasks first
            if (!isCompleted) {
                if (ImGui::Checkbox(("##check" + std::to_string(i)).c_str(), &isCompleted)) {
                    taskStatus[i] = isCompleted ? 1 : 0; // Update task status
                }
                ImGui::SameLine();
                ImGui::Text("%d. %s", taskNumber++, tasks[i].c_str()); // Display task text with numbering
                ImGui::SameLine();
                if (ImGui::Button(("Remove##" + std::to_string(i)).c_str())) {
                    removeTask(i);
                }
            }
        }

        // Display completed tasks next
        for (int i = 0; i < tasks.size(); i++) {
            if (taskStatus[i] == 1) { // Completed task
                ImGui::Text("%d. %s (Completed)", taskNumber++, tasks[i].c_str()); // Display completed task with numbering
            }
        }

        ImGui::EndChild();
        ImGui::End();

        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.15f, 0.18f, 0.2f, 1.00f); // Background color
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
