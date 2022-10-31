namespace Lab3.Models.OneToMany
{
    public class Model2
    {
        public string Name { get; set; }
        public Model1 Model1 { get; set; }
        public Guid Model1Id { get; set; }
    }
}
