package RESTapp;

import java.util.HashSet;
import java.util.Set;

import javax.ws.rs.ApplicationPath;
import javax.ws.rs.core.Application;


@ApplicationPath("API")
public class AppSetup extends Application {
	private Set<Class<?>> resources = new HashSet<>();

	public AppSetup() {
		System.out.println("Application Created !");
		resources.add(ResourcesV1.class);
		resources.add(ResourcesV2.class);
	}

	@Override
	public Set<Class<?>> getClasses() {
		return resources;
	}

}
