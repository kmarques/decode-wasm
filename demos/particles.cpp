extern "C"
{
    void simulate_particles(float *particles, int number_particles, float speed)
    {
        for (int i = 0; i < number_particles; i++)
        {
            particles[i] += speed;
        }
    }
}