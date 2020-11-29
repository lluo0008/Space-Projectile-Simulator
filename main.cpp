// Dear ImGui: standalone example application for DirectX 11
// If you are new to Dear ImGui, read documentation from the docs/ folder + read the top of imgui.cpp.
// Read online: https://github.com/ocornut/imgui/tree/master/docs

#include "imgui.h"
#include "iostream"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx11.h"
#include <d3d11.h>
#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#include <tchar.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"         // NULL, malloc, free, atoi

#include "ProjectileManager.h"

// Data
static ID3D11Device* g_pd3dDevice = NULL;
static ID3D11DeviceContext* g_pd3dDeviceContext = NULL;
static IDXGISwapChain* g_pSwapChain = NULL;
static ID3D11RenderTargetView* g_mainRenderTargetView = NULL;

// Forward declarations of helper functions
bool CreateDeviceD3D(HWND hWnd);
void CleanupDeviceD3D();
void CreateRenderTarget();
void CleanupRenderTarget();
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
bool LoadTextureFromFile(const char*, ID3D11ShaderResourceView**, int*, int*);

// Main code
int main(int, char**)
{
    // Create application window
    //ImGui_ImplWin32_EnableDpiAwareness();
    WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, _T("ImGui Example"), NULL };
    ::RegisterClassEx(&wc);
    HWND hwnd = ::CreateWindow(wc.lpszClassName, _T("Projectile Simulator"), WS_OVERLAPPEDWINDOW, 100, 100, 750, 500, NULL, NULL, wc.hInstance, NULL);

    // Initialize Direct3D
    if (!CreateDeviceD3D(hwnd))
    {
        CleanupDeviceD3D();
        ::UnregisterClass(wc.lpszClassName, wc.hInstance);
        return 1;
    }

    // Show the window
    ::ShowWindow(hwnd, SW_SHOWDEFAULT);
    ::UpdateWindow(hwnd);

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Dear ImGui style
    //ImGui::StyleColorsDark();
    ImGui::StyleColorsClassic();

    // Setup Platform/Renderer backends
    ImGui_ImplWin32_Init(hwnd);
    ImGui_ImplDX11_Init(g_pd3dDevice, g_pd3dDeviceContext);

    // Our state
    bool show_demo_window = true;
    bool show_another_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    enum Screen {
        SCREEN_HOME,
        SCREEN_SELECT,
        SCREEN_LAUNCH
    };

    static int state = SCREEN_HOME;    // init to home screen
    Environments planet = EARTH;       // default state is Earth
    Size selectedProjectile = MEDIUM;  // default state is medium projectile; 
    static int windSpeed = 7;          // default wind speed;
    Environment* env = new Environment(EARTH, windSpeed);                           // init a placeholder null environment
    ProjectileManager* manager = new ProjectileManager(env, selectedProjectile);    // init a placeholder null projectilemanager
	bool isLaunched = false;
	bool selectStart = true;

    /*
    ==================== Load Textures ==================== 
    */
    
    ID3D11ShaderResourceView* stars = NULL;
    int stars_width = 0, stars_height = 0;
    bool ret = LoadTextureFromFile("assets/stars.jpg", &stars, &stars_width, &stars_height);
    IM_ASSERT(ret);

    // JUPITER
    ID3D11ShaderResourceView* jupiter = NULL;
    int jupiter_width = 0, jupiter_height = 0;
    ret = LoadTextureFromFile("assets/jupiter.png", &jupiter, &jupiter_width, &jupiter_height);
    IM_ASSERT(ret);

    // MARS
    ID3D11ShaderResourceView* mars = NULL;
    int mars_width = 0, mars_height = 0;
    ret = LoadTextureFromFile("assets/mars.png", &mars, &mars_width, &mars_height);
    IM_ASSERT(ret);

    // MOON
    ID3D11ShaderResourceView* moon = NULL;
    int moon_width = 0, moon_height = 0;
    ret = LoadTextureFromFile("assets/moon.png", &moon, &moon_width, &moon_height);
    IM_ASSERT(ret);

    // EARTH
    ID3D11ShaderResourceView* earth = NULL;
    int earth_width = 0, earth_height = 0;
    ret = LoadTextureFromFile("assets/earth.png", &earth, &earth_width, &earth_height);
    IM_ASSERT(ret);

    // ROCKET
    ID3D11ShaderResourceView* rocket = NULL;
    int rocket_width = 0, rocket_height = 0;
    ret = LoadTextureFromFile("assets/rocket.png", &rocket, &rocket_width, &rocket_height);
    IM_ASSERT(ret);

    // JUPITER SURFACE
    ID3D11ShaderResourceView* jupiter_surface = NULL;
    int jupiter_surface_width = 0, jupiter_surface_height = 0;
    ret = LoadTextureFromFile("assets/jupiter_surface.png", &jupiter_surface, &jupiter_surface_width, &jupiter_surface_height);
    IM_ASSERT(ret);

    // MARS SURFACE
    ID3D11ShaderResourceView* mars_surface = NULL;
    int mars_surface_width = 0, mars_surface_height = 0;
    ret = LoadTextureFromFile("assets/mars_surface.png", &mars_surface, &mars_surface_width, &mars_surface_height);
    IM_ASSERT(ret);

    // MOON SURFACE
    ID3D11ShaderResourceView* moon_surface = NULL;
    int moon_surface_width = 0, moon_surface_height = 0;
    ret = LoadTextureFromFile("assets/moon_surface.png", &moon_surface, &moon_surface_width, &moon_surface_height);
    IM_ASSERT(ret);

    // EARTH SURFACE
    ID3D11ShaderResourceView* earth_surface = NULL;
    int earth_surface_width = 0, earth_surface_height = 0;
    ret = LoadTextureFromFile("assets/earth_surface.png", &earth_surface, &earth_surface_width, &earth_surface_height);
    IM_ASSERT(ret);

    // CANNON
    ID3D11ShaderResourceView* cannon = NULL;
    int cannon_width = 0, cannon_height = 0;
    ret = LoadTextureFromFile("assets/cannon_45.png", &cannon, &cannon_width, &cannon_height);
    IM_ASSERT(ret);

    // SQUARE
    ID3D11ShaderResourceView* square = NULL;
    int square_width = 0, square_height = 0;
    ret = LoadTextureFromFile("assets/square.png", &square, &square_width, &square_height);
    IM_ASSERT(ret);

    // PROJECTILE
    ID3D11ShaderResourceView* projectile = NULL;
    int projectile_height = 0, projectile_width = 0;
    ret = LoadTextureFromFile("assets/projectile2.png", &projectile, &projectile_height, &projectile_width);
    IM_ASSERT(ret);

    // Main loop
    MSG msg;
    ZeroMemory(&msg, sizeof(msg));
    while (msg.message != WM_QUIT)
    {
        // Poll and handle messages (inputs, window resize, etc.)
        // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
        // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application.
        // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application.
        // Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
        if (::PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
        {
            ::TranslateMessage(&msg);
            ::DispatchMessage(&msg);
            continue;
        }

        // Start the Dear ImGui frame
        ImGui_ImplDX11_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();

        // 2. Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
        {
            ImGui::SetNextWindowPos(ImVec2(-10, -10));
            ImGui::SetNextWindowSize(ImVec2(750, 510), 0);

            ImGui::Begin("physics sim", NULL, ImGuiWindowFlags_NoDecoration);
            ImGui::Image((void*)stars, ImVec2(750, 470));

            if (state == SCREEN_HOME)
            {
                // Title
                ImGui::SetCursorPos(ImVec2(300, 40));
                ImGui::Text("PROJECTILE SIMULATOR");

                // Jupiter TODO add button trigger
                ImGui::SetCursorPos(ImVec2(400, 80));
                ImGui::Image(jupiter, ImVec2(jupiter_width, jupiter_height));
                ImGui::SetCursorPos(ImVec2(510, 410));
                if (ImGui::Button("jupiter", ImVec2(100, 50)))
                {
                    state = SCREEN_SELECT;
                    planet = JUPITER;
                    env = new Environment(planet, windSpeed);
                    manager = new ProjectileManager(env, selectedProjectile);
					selectStart = true;
                }

                // Mars TODO add button trigger
                ImGui::SetCursorPos(ImVec2(270, 100));
                ImGui::Image(mars, ImVec2(mars_width * 0.4, mars_height * 0.4));
                ImGui::SetCursorPos(ImVec2(280, 190));
                if (ImGui::Button("mars", ImVec2(70, 30)))
                {
                    state = SCREEN_SELECT;
                    planet = MARS;
                    env = new Environment(planet, windSpeed);
                    manager = new ProjectileManager(env, selectedProjectile);
					selectStart = true;
                }

                // Moon TODO add button trigger
                ImGui::SetCursorPos(ImVec2(150, 200));
                ImGui::Image(moon, ImVec2(moon_width * 0.3, moon_height * 0.3));
                ImGui::SetCursorPos(ImVec2(135, 250));
                if (ImGui::Button("moon", ImVec2(70, 30)))
                {
                    state = SCREEN_SELECT;
                    planet = MOON;
                    env = new Environment(planet, windSpeed);
                    manager = new ProjectileManager(env, selectedProjectile);
					selectStart = true;
                }

                // Earth TODO add button trigger
                ImGui::SetCursorPos(ImVec2(30, 270));
                ImGui::Image(earth, ImVec2(earth_width / 1.5, earth_height / 1.5));
                ImGui::SetCursorPos(ImVec2(55, 420));
                if (ImGui::Button("earth", ImVec2(80, 40)))
                {
                    state = SCREEN_SELECT;
                    planet = EARTH;
                    env = new Environment(planet, windSpeed);
                    manager = new ProjectileManager(env, selectedProjectile);
					selectStart = true;
                }

                // Rocket Graphic
                ImGui::SetCursorPos(ImVec2(10, 300));
                ImGui::Image((void*)rocket, ImVec2(rocket_width * 0.25, rocket_height * 0.25));
            }

            if (state == SCREEN_SELECT) {
                // place ground
                ImGui::SetCursorPos(ImVec2(0, 400));
                switch (planet) {
                case 0: ImGui::Image((void*)earth_surface, ImVec2(750, earth_surface_height)); break;
                case 1: ImGui::Image((void*)moon_surface, ImVec2(750, moon_surface_height)); break;
                case 2: ImGui::Image((void*)mars_surface, ImVec2(750, mars_surface_height)); break;
                case 3: ImGui::Image((void*)jupiter_surface, ImVec2(750, jupiter_surface_height)); break;
                }

                // Planet label
                ImGui::SetCursorPos(ImVec2(350, 440));
                ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(ImColor(0, 0, 0)));
                switch (planet) {
                case 0: ImGui::Text("Earth"); break;
                case 1: ImGui::Text("Moon"); break;
                case 2: ImGui::Text("Mars"); break;
                case 3: ImGui::Text("Jupiter"); break;
                }
                ImGui::PopStyleColor();

                //display cannon
                ImGui::SetCursorPos(ImVec2(0, 350));
                ImGui::Image((void*)cannon, ImVec2(cannon_width / 2, cannon_height / 2));

                // Commented for now; no changing environment functionality
                //ImGui::SetCursorPos(ImVec2(40, 40));
                //ImGui::Button("Home", ImVec2(75, 30));

                ImGui::SetCursorPos(ImVec2(650, 380));
                if (ImGui::Button("Next", ImVec2(75, 30))) {
					if (!selectStart) {
						manager->setProjectileSize(selectedProjectile);
						state = SCREEN_LAUNCH;
					}
                }
                 
				if (!selectStart) {
					// Highlight selected projectile in red
					if (selectedProjectile == SMALL)
						ImGui::SetCursorPos(ImVec2(145, 145));
					else if (selectedProjectile == MEDIUM)
						ImGui::SetCursorPos(ImVec2(320, 145));
					else if (selectedProjectile == LARGE)
						ImGui::SetCursorPos(ImVec2(495, 145));
					else
						ImGui::SetCursorPos(ImVec2(1000, 1000));
					ImGui::Image((void*)square, ImVec2(117, 117));
				}

                // Begin Large Projectile
                ImGui::SetCursorPos(ImVec2(500, 150));
                ImGui::Image(projectile, ImVec2(100, 100));

                ImGui::SetCursorPos(ImVec2(523, 115));
				if (ImGui::Button("Select##1", ImVec2(60, 20))) {
					selectedProjectile = LARGE;
					selectStart = false;
				}

                ImGui::SetCursorPos(ImVec2(500, 275));
                ImGui::Text("Properties: \n - Radius: 10 \n - Density: 1900 kg/m^3 \n - Mass: 0.01 kg");
                // End Large Projectile

                // Begin Medium Projectile
                ImGui::SetCursorPos(ImVec2(347.5, 162.5));
                ImGui::Image(projectile, ImVec2(75, 75));

                ImGui::SetCursorPos(ImVec2(347, 115));
				if (ImGui::Button("Select##2", ImVec2(60, 20))) {
					selectedProjectile = MEDIUM;
					selectStart = false;
				}

                ImGui::SetCursorPos(ImVec2(325, 275));
                ImGui::Text("Properties: \n - Radius: 5 \n - Density: 1900 kg/m^3 \n - Mass: 0.1 kg");
                // End Medium Projectile

                // Begin Small Projectile
                ImGui::SetCursorPos(ImVec2(195 - 12.5, 195 - 12.5));
                ImGui::Image(projectile, ImVec2(25, 25));

                ImGui::SetCursorPos(ImVec2(173, 115));
				if (ImGui::Button("Select##3", ImVec2(60, 20))) {
					selectedProjectile = SMALL;
					selectStart = false;
				}

                ImGui::SetCursorPos(ImVec2(150, 275));
                ImGui::Text("Properties: \n - Radius: 1 \n - Density: 1900 kg/m^3 \n - Mass: 1 kg");
                // End Small Projectile

				ImGui::SetCursorPos(ImVec2(300, 50));

				if (!selectStart) {

					if (selectedProjectile == SMALL)
						ImGui::Text("Selected Projectile: SMALL");
					else if (selectedProjectile == MEDIUM)
						ImGui::Text("Selected Projectile: MEDIUM");
					else
						ImGui::Text("Selected Projectile: LARGE");

				}
				else {

					ImGui::Text("Selected Projectile: NONE");

				}

                
            }

            if (state == SCREEN_LAUNCH) {
                static int counter = 0;

                // place ground
                ImGui::SetCursorPos(ImVec2(0, 400));
                switch (planet) {
                case 0: ImGui::Image((void*)earth_surface, ImVec2(750, earth_surface_height)); break;
                case 1: ImGui::Image((void*)moon_surface, ImVec2(750, moon_surface_height)); break;
                case 2: ImGui::Image((void*)mars_surface, ImVec2(750, mars_surface_height)); break;
                case 3: ImGui::Image((void*)jupiter_surface, ImVec2(750, jupiter_surface_height)); break;
                }

                // Planet label
                ImGui::SetCursorPos(ImVec2(350, 440));
                ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(ImColor(0, 0, 0)));
                switch (planet) {
                case 0: ImGui::Text("Earth"); break;
                case 1: ImGui::Text("Moon"); break;
                case 2: ImGui::Text("Mars"); break;
                case 3: ImGui::Text("Jupiter"); break;
                }
                ImGui::PopStyleColor();

                //display cannon
                ImGui::SetCursorPos(ImVec2(0, 350));
                ImGui::Image((void*)cannon, ImVec2(cannon_width / 2, cannon_height / 2));

                //Wind Control
                ImGui::SetCursorPos(ImVec2(410, 40));
                ImGui::PushItemWidth(230);
                ImGui::SliderInt("Wind(m/s)", &windSpeed, -10, 10);            // Edit wind using a slider from -10 to 10
                ImGui::PopItemWidth();

                //Home button
                //ImGui::SetCursorPos(ImVec2(40, 40));
                //ImGui::Button("Home", ImVec2(75, 30));

                //Back button
                ImGui::SetCursorPos(ImVec2(40, 80));
                if (ImGui::Button("Back", ImVec2(75, 30))) {
                    state = SCREEN_SELECT;
					isLaunched = false;
                }

                //Launch button
                ImGui::SetCursorPos(ImVec2(630, 80));
                ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(ImColor(225, 44, 3)));
                if (ImGui::Button("LAUNCH", ImVec2(88, 40))) {
                    manager->setWindSpeed(windSpeed);
                    manager->launchCurrent();
					isLaunched = true;
                }
                ImGui::PopStyleColor();

                // Confirm that projectileManager is launching to the vector
                //ImGui::SetCursorPos(ImVec2(100, 100));
                //ImGui::Text("PROJ: %d", manager->getLaunchedProjectiles().size());

                //Compare button
                ImGui::SetCursorPos(ImVec2(630, 130));
                if (ImGui::Button("Planet Info", ImVec2(90, 30))) {
                    ImGui::OpenPopup("Planet Info");
                }

                ImVec2 center(ImGui::GetIO().DisplaySize.x * 0.5f, ImGui::GetIO().DisplaySize.y * 0.5f);
                ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
                ImGui::SetNextWindowSize(ImVec2(400, 180));
                if (ImGui::BeginPopupModal("Planet Info"))
                {
                    switch (planet) {
                    case 0: ImGui::Text("Earth"); 
                        ImGui::Separator();
                        ImGui::TextWrapped("Earth's atmosphere is multi-layered, strong, and life-sustaining - it is about 300 miles in thickness. Earth's gravity "
                            "is about 9.8 m/s.");
                        break;
                    case 1: ImGui::Text("Moon"); 
                        ImGui::Separator();
                        ImGui::TextWrapped("The moon's gravity is about 1.6 m/s, much weaker than on Earth. Someone who weighs 180lbs on Earth would "
                            "only weigh 30lbs on the moon. There is a very thin layer of gases on the moon's surface that can almost be considered an atmosphere. ");
                        break;
                    case 2: ImGui::Text("Mars"); 
                        ImGui::Separator();
                        ImGui::TextWrapped("Mars has a very thin atmosphere, much thinner than Earth. It is still thick enough "
                            "to support weather, clouds and winds. Dust is a permanent part of the atmosphere - its dust storms are the "
                            "largest in the solar system, capable of blanketing the entire planet and lasting for months at a time.");
                        break;
                    }
                    ImGui::SetCursorPos(ImVec2(150, 150));
                    if (ImGui::Button("Close", ImVec2(100, 0))) { ImGui::CloseCurrentPopup(); }
                    ImGui::EndPopup();
                }

                //Exception for Jupiter
                if (planet == JUPITER) {
                    ImGui::OpenPopup("!!!");
                }

                ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
                ImGui::SetNextWindowSize(ImVec2(400, 200));
                if (ImGui::BeginPopupModal("!!!"))
                {
                    ImGui::TextWrapped("Jupiter is a gas giant - its atmosphere is made up of mostly hydrogen gas and helium gas, like the sun. "
                        "Jupiter has winds that range from 192mph to 335 mph, and experiences massive and violent storms. Its magnetic field is 16 to 54 times stronger than the magnetic field on Earth. ");
                    ImGui::Separator();
                    ImGui::TextWrapped("Due to these extreme conditions, any projectile that we try to launch on Jupiter is vaporized immediately!");
                    ImGui::EndPopup();
                }

				manager->update();

				vector<Projectile> projectiles = manager->getLaunchedProjectiles();

				for (Projectile i : projectiles) {

                    ImVec4 color = ImVec4(1, 1, 1, 1);
                    switch (i.getColor()) {
                    case RED: color = ImVec4(255, 0, 0, 1); break;
                    case GREEN: color = ImVec4(0, 255, 0, 1); break;
                    case BLUE: color = ImVec4(0, 0, 255, 1);  break;
                    case ORANGE: color = ImVec4(1, 0.27, 0, 1); break;
                    case YELLOW: color = ImVec4(255, 255, 0, 1); break;
                    case PINK: color = ImVec4(255, 192, 203, 1); break;
                    case BLACK: color = ImVec4(0, 0, 0, 1); break;
                    case WHITE: color = ImVec4(1, 1, 1, 0.5); break;
                    case PURPLE: color = ImVec4(128, 0, 128, 1); break;
                    case BROWN: color = ImVec4(96, 75, 0, 1); break;
                    }

					if (i.getSize() == SMALL) {

						ImGui::SetCursorPos(ImVec2(i.getData().x + 110, 425 - i.getData().y));
                        ImGui::Image(projectile, (ImVec2(20, 20)), ImVec2(0, 0), ImVec2(1, 1), color);

						//Used for testing
						/*ImGui::SetCursorPos(ImVec2(300, 50));
						ImGui::Text("x1 = %d", i.getData().x);
						ImGui::SetCursorPos(ImVec2(300, 100));
						ImGui::Text("y1 = %d", i.getData().y);*/

					} else if (i.getSize() == MEDIUM) {

						ImGui::SetCursorPos(ImVec2(i.getData().x + 110, 400 - i.getData().y));
                        ImGui::Image(projectile, (ImVec2(40, 40)), ImVec2(0, 0), ImVec2(1, 1), color);

						//Used for testing
						/*ImGui::SetCursorPos(ImVec2(300, 50));
						ImGui::Text("x2 = %d", i.getData().x);
						ImGui::SetCursorPos(ImVec2(300, 100));
						ImGui::Text("y2 = %d", i.getData().y);*/

					} else {

						ImGui::SetCursorPos(ImVec2(i.getData().x + 110, 415 - i.getData().y));
                        ImGui::Image(projectile, (ImVec2(60, 60)), ImVec2(0, 0), ImVec2(1, 1), color);

						//Used for testing
						/*ImGui::SetCursorPos(ImVec2(300, 50));
						ImGui::Text("x3 = %d", i.getData().x);
						ImGui::SetCursorPos(ImVec2(300, 100));
						ImGui::Text("y3 = %d", i.getData().y);*/

					}

				}
				
				
            }
            ImGui::End();
        }       

        // Rendering
        ImGui::Render();
        g_pd3dDeviceContext->OMSetRenderTargets(1, &g_mainRenderTargetView, NULL);
        g_pd3dDeviceContext->ClearRenderTargetView(g_mainRenderTargetView, (float*)&clear_color);
        ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

        g_pSwapChain->Present(1, 0); // Present with vsync
        //g_pSwapChain->Present(0, 0); // Present without vsync
    }

    // Cleanup
    ImGui_ImplDX11_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();
    delete env;
    delete manager;

    CleanupDeviceD3D();
    ::DestroyWindow(hwnd);
    ::UnregisterClass(wc.lpszClassName, wc.hInstance);

    return 0;
}

// Helper functions
bool LoadTextureFromFile(const char* filename, ID3D11ShaderResourceView** out_srv, int* out_width, int* out_height)
{
    // Load from disk into a raw RGBA buffer
    int image_width = 0;
    int image_height = 0;
    unsigned char* image_data = stbi_load(filename, &image_width, &image_height, NULL, 4);
    if (image_data == NULL)
        return false;

    // Create texture
    D3D11_TEXTURE2D_DESC desc;
    ZeroMemory(&desc, sizeof(desc));
    desc.Width = image_width;
    desc.Height = image_height;
    desc.MipLevels = 1;
    desc.ArraySize = 1;
    desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    desc.SampleDesc.Count = 1;
    desc.Usage = D3D11_USAGE_DEFAULT;
    desc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
    desc.CPUAccessFlags = 0;

    ID3D11Texture2D* pTexture = NULL;
    D3D11_SUBRESOURCE_DATA subResource;
    subResource.pSysMem = image_data;
    subResource.SysMemPitch = desc.Width * 4;
    subResource.SysMemSlicePitch = 0;
    g_pd3dDevice->CreateTexture2D(&desc, &subResource, &pTexture);

    // Create texture view
    D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc;
    ZeroMemory(&srvDesc, sizeof(srvDesc));
    srvDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    srvDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
    srvDesc.Texture2D.MipLevels = desc.MipLevels;
    srvDesc.Texture2D.MostDetailedMip = 0;
    g_pd3dDevice->CreateShaderResourceView(pTexture, &srvDesc, out_srv);
    pTexture->Release();

    *out_width = image_width;
    *out_height = image_height;
    stbi_image_free(image_data);

    return true;
}

bool CreateDeviceD3D(HWND hWnd)
{
    // Setup swap chain
    DXGI_SWAP_CHAIN_DESC sd;
    ZeroMemory(&sd, sizeof(sd));
    sd.BufferCount = 2;
    sd.BufferDesc.Width = 0;
    sd.BufferDesc.Height = 0;
    sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    sd.BufferDesc.RefreshRate.Numerator = 60;
    sd.BufferDesc.RefreshRate.Denominator = 1;
    sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    sd.OutputWindow = hWnd;
    sd.SampleDesc.Count = 1;
    sd.SampleDesc.Quality = 0;
    sd.Windowed = TRUE;
    sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

    UINT createDeviceFlags = 0;
    //createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
    D3D_FEATURE_LEVEL featureLevel;
    const D3D_FEATURE_LEVEL featureLevelArray[2] = { D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_0, };
    if (D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, createDeviceFlags, featureLevelArray, 2, D3D11_SDK_VERSION, &sd, &g_pSwapChain, &g_pd3dDevice, &featureLevel, &g_pd3dDeviceContext) != S_OK)
        return false;

    CreateRenderTarget();
    return true;
}

void CleanupDeviceD3D()
{
    CleanupRenderTarget();
    if (g_pSwapChain) { g_pSwapChain->Release(); g_pSwapChain = NULL; }
    if (g_pd3dDeviceContext) { g_pd3dDeviceContext->Release(); g_pd3dDeviceContext = NULL; }
    if (g_pd3dDevice) { g_pd3dDevice->Release(); g_pd3dDevice = NULL; }
}

void CreateRenderTarget()
{
    ID3D11Texture2D* pBackBuffer;
    g_pSwapChain->GetBuffer(0, IID_PPV_ARGS(&pBackBuffer));
    g_pd3dDevice->CreateRenderTargetView(pBackBuffer, NULL, &g_mainRenderTargetView);
    pBackBuffer->Release();
}

void CleanupRenderTarget()
{
    if (g_mainRenderTargetView) { g_mainRenderTargetView->Release(); g_mainRenderTargetView = NULL; }
}

// Forward declare message handler from imgui_impl_win32.cpp
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// Win32 message handler
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
        return true;

    switch (msg)
    {
    case WM_SIZE:
        if (g_pd3dDevice != NULL && wParam != SIZE_MINIMIZED)
        {
            CleanupRenderTarget();
            g_pSwapChain->ResizeBuffers(0, (UINT)LOWORD(lParam), (UINT)HIWORD(lParam), DXGI_FORMAT_UNKNOWN, 0);
            CreateRenderTarget();
        }
        return 0;
    case WM_SYSCOMMAND:
        if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
            return 0;
        break;
    case WM_DESTROY:
        ::PostQuitMessage(0);
        return 0;
    }
    return ::DefWindowProc(hWnd, msg, wParam, lParam);
}
